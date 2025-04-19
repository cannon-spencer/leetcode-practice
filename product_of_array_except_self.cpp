class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            // since this needs to be completed in O(n) time complexity we can only loop
            // over the array nums once and must update everything in the answer without
            // explicity looping over that as well
    
            vector<int> answer(nums.size(), 1); // init answer vector
    
            // loop over nums and set the left side product to every index of answer
            int leftProduct = 1;
            for(int i = 1; i < nums.size(); i++){
                leftProduct *= nums[i - 1];
                answer[i] = leftProduct;
            }
    
            // same deal but multiply the right side product by looping in reverse
            int rightProduct = 1;
            for(int i = nums.size() - 2; i >= 0; i--){
                rightProduct *= nums[i + 1];
                answer[i] *= rightProduct;
            }
    
            return answer;
    
        }
    };