class Solution {
    public:
        
        // triplets that sum to zero, note that we dont need the indexes
        // but no duplicate indexes can be used
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> output;
    
            // sort since we dont really care about index
            std::sort(nums.begin(), nums.end());
    
            for(int p1 = 0; p1 < nums.size() - 2; p1++){
                // skip duplicates for p1
                if ((p1 > 0) && (nums[p1] == nums[p1 - 1]))
                    continue;
    
                int p2 = p1 + 1;
                int p3 = nums.size() - 1;
    
                while(p2 < p3){
                    int sum = nums[p1] + nums[p2] + nums[p3];
    
                    if(sum == 0){
                        output.push_back({nums[p1], nums[p2], nums[p3]});
    
                        //move p2 and p3
                        p2++; p3--;
    
                        // skip over duplicates
                        while ((p2 < p3) && (nums[p2] == nums[p2 - 1]))
                            p2++;
                        while ((p2 < p3) && (nums[p3] == nums[p3 + 1]))
                            p3--;
    
                    } else if (sum < 0) {
                        p2++;
                    } else {
                        p3--;
                    }
                }
    
            }    
    
            return output;
    
        }
    };