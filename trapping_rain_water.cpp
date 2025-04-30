class Solution {
public:
    // the first approach is O(n) memory and time if we store some extra information like
    // the max height coming from the left and the right at each location ahead of time
    /*int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeftArr(n);
        vector<int> maxRightArr(n);

        // scan through array going left
        int maxLeft = 0;
        for(int i = 1; i < n; i++){
            maxLeft = std::max(maxLeft, height[i - 1]);
            maxLeftArr[i] = maxLeft;
        }

        // do the same thing coming from the right
        int maxRight = 0;
        for(int i = n - 2; i >= 0; i--){
            maxRight = std::max(maxRight, height[i + 1]);
            maxRightArr[i] = maxRight;

        }

        // now scan through the array again and calculate the water held at each pos
        // exclude edges because we dont need to check
        int totalWater = 0;
        for(int i = 1; i < n - 1; i++){
            int waterAtPos = std::min(maxLeftArr[i], maxRightArr[i]) - height[i];
            
            // sum water only if it is positive
            totalWater += (waterAtPos > 0) ? waterAtPos : 0;
        }

        return totalWater;
    }*/

    // we can also get a two pointer approach to save on memory used. The trick is 
    // updating at the left and the right at the same time using the min of the heights
    // we currently have
    int trap(vector<int>& height) {
        int n = height.size();
        // init maxes to the edges
        int leftMax = height[0], rightMax = height[n - 1];

        // excluding edges because they cant hold water anyways
        int leftPtr = 0, rightPtr = n - 1;

        int ans = 0;

        while(leftPtr < rightPtr){
            
            // increment lower max val
            if(leftMax < rightMax){
                leftPtr++;
                leftMax = std::max(leftMax, height[leftPtr]);
                ans += leftMax - height[leftPtr];
            } else {
                rightPtr--;
                rightMax = std::max(rightMax, height[rightPtr]);
                ans += rightMax - height[rightPtr];
            }
        }

        return ans;
        
    }
};
