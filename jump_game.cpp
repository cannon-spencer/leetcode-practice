lass Solution {
    public:
        bool canJump(vector<int>& nums) {
            // the only way we can't make it to the end is if there's a 0 we cant jump over
            // so we traverse backwards through nums and if we hit a zero we need to determine
            // if we can jump over it 
    
            int minJump = 0;
            int n = nums.size();
    
            if(n == 1) return true;
    
            for(int i = n - 2; i >= 0; i--){
                
                // hit a zero
                if(nums[i] == 0){
                    minJump++;
                }
                
                // we've hit some sort of zero prior (and cant jump over it yet)
                else if(minJump > 0){
                    
                    // check if we need increase minjump this turn
                    if(nums[i] > minJump){
                        minJump = 0;
                    } else {
                        minJump++;
                    }
                }
            }
    
            return minJump == 0;
    
        }
    };