class Solution {
    public:
        // O(n) solution - creates new array
        /*void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> newArr(n);
            for(int i = 0; i < n; i++){
                newArr[(i + k) % n] = nums[i];
            }
            nums = newArr;
        }*/
    
    
        // Solve in-place for O(1) memory usage
        void rotate(vector<int>& nums, int k) {
            k = k % nums.size();
            
            // reverse entire array
            reverse(nums.begin(), nums.end());
    
            // reverse the first k elements
            reverse(nums.begin(), nums.begin() + k);
    
            // reverse the remaining elements
            reverse(nums.begin() + k, nums.end());
        }
    };