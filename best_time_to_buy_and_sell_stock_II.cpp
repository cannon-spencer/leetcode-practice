class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = INT_MAX;
            int profit = 0;
    
            for(int price : prices){
    
                // update min price
                minPrice = min(minPrice, price);
    
                // Update profits, if any
                if(price - minPrice > 0){
                    profit += price - minPrice;
                    minPrice = price;
                }
            }
    
            return profit;
        }
    };