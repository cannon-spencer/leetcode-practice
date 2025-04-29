class Solution {
public:
    // O(n) space and O(n) time approach
    /*int candy(vector<int>& ratings) {
        // if we iterate over the array twice and make sure each with a higher ranking gets more than
        // their neihbor in the left and right direction, we can extract the min candies needed
        int n = ratings.size();

        // init output with 1s (min 1 candy per)
        vector<int> candies(n, 1);

        // left check - if the rating is higher, increase the candy count by 1
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i -1])
                candies[i] = candies[i - 1] + 1;
        }

        // do the same in reverse
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1] + 1);
        }

        // collect the candy count
        int sum = 0;
        for(int candy : candies){
            sum += candy;
        }

        return sum;
    }*/

    // O(1) space apprach by keeping track of peaks
    int candy(vector<int>& ratings) {
        
        // up/down for tracking slope
        // peak keeps track of candies at peak
        // total keeps track of total candies, start at 1 for first
        int up = 0, down = 0, peak = 1, total = 1;
        
        for(int i = 1; i < ratings.size(); i++){
            // rating is going up
            if(ratings[i] > ratings[i - 1]){
                up++; down = 0;
                peak = up + 1;
                total += peak;
            } 
            
            // rating is going down
            else if (ratings[i] < ratings[i - 1]){
                down++; up = 0;
                total += down;
                if(down >= peak) total += 1;
            } 
            
            // rating is equal to last
            else {
                up = down = 0;
                peak = 1;
                total += 1;
            }
        }

        return total;

    }
};
