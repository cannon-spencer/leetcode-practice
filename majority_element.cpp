class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            // key = number
            // val = number count
            std::unordered_map<int, int> myMap;
    
            const int majorityElement = nums.size() / 2;
            
            for(int val : nums){
                // increment the count of the stored variable, then see if it
                // is large enough to return the answer
                if(++myMap[val] > majorityElement)
                    return val;
            }
    
            return -1;
        }
    };