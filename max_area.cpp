class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxArea = 0;
            int front = 0;
            int back = height.size() - 1;
            // use two pointer approach to iterativly calculate the max height
            // between each two poles
    
            while(front != back){
                // height * width
                int area = std::min(height[front], height[back]) * (back - front);
    
                // update max if we have a new higher max
                maxArea = std::max(maxArea, area);
    
                // increment smaller of the two pointers
                if(height[front] > height[back]) back--;
                else front++;
            }
    
            return maxArea;
        
        }
    };