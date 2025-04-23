class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            // the goal is to use O(1) extra space so you can't use a hashmap to keep track of numbers or anything like that
            // using two pointers on the high and low end we can itertitvly find the right sum
    
            // approach: use low and high pointer, if the sum is too high, decrement the high pointer, 
            // if it is too small increment the small pointer.
    
            // input will be at least two elements
    
            int lowPointer = 0;
            int highPointer = numbers.size() - 1;
    
            while(highPointer > lowPointer){
                int sum = numbers[lowPointer] + numbers[highPointer];
    
                if(sum > target){
                    highPointer--;
                } else if (sum < target) {
                    lowPointer++;
                } else {
                    return {lowPointer + 1, highPointer + 1};
                }
            }
    
            return {-1, -1};
        }
    };