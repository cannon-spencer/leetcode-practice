class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // if array is 2 or smaller the answer doesnt really matter
            if(nums.size() < 2) return nums.size();
            
            int k = vi1;
            for(int i = 2; i < nums.size(); i++){
                if(nums[k - 1] != nums[i]){
                    nums[++k] = nums[i];
                }
            }
    
            return k + 1;
        }
    };