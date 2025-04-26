class Solution {
    public:
        // solution 1: brute force O(n^2)
        /*vector<int> twoSum(vector<int>& nums, int target) {
            for(int i = 0; i < nums.size() - 1; i++){
                for(int j = i + 1; j < nums.size(); j++){
                    if(nums[i] + nums[j] == target)
                        return {i, j};
                }
            }
            return {-1};
        } */
    
        // solution 2: hash map single pass O(n) running but also o(n) extra space
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> prevNums; // key = prev num, val = index
            
            for(int i = 0; i < nums.size(); i++){
                // (nums[i] + complement) == target
                int complement = target - nums[i];
    
                // if complement exists, we know its a valid pair so return index
                // and the index to the complement number
                if(prevNums.count(complement))
                    return {i, prevNums[complement]};
                
                // update hash map at each step
                prevNums[nums[i]] = i;
            }
    
            return {-1};
        } 
    
        // solution 3: use two pointer + sorting which results in O(logn) for sorting
        // then O(n) for the two pointer search, thus O(nlogn). The one problem is we
        // lose the indexes if we sort so we have to store them manually in O(n) extra space
        /*vector<int> twoSum(vector<int>& nums, int target) { 
            vector<std::pair<int,int>> numsIndex(nums.size());
    
            // initalize the indexed array
            for(int i = 0; i < nums.size(); i++){
                numsIndex[i].first = nums[i];
                numsIndex[i].second = i;
            }
    
            // sort with standard library
            std::sort(numsIndex.begin(), numsIndex.end());
    
            int p1 = 0, p2 = numsIndex.size() - 1;
            while(p1 != p2){
                if((numsIndex[p1].first + numsIndex[p2].first) == target)
                    return {numsIndex[p1].second, numsIndex[p2].second};
                else if ((numsIndex[p1].first + numsIndex[p2].first) > target)
                    p2--;
                else
                    p1++;
            }
    
            return {-1};
        } */
    
    };