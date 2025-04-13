class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            int minPrice = INT_MAX;
    
            for(int price : prices){
    
                // update min price
                minPrice = min(price, minPrice);
    
                // update max profit possible
                maxProfit = max(price - minPrice, maxProfit);
    
            }
    
            if(maxProfit == 0 || minPrice == INT_MAX)
                return 0;
            
            return maxProfit;
        }
    };