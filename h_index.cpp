class Solution {
    public:
        int hIndex(vector<int>& citations) {
            // first we sort the citations in decending order
            std::sort(citations.begin(), citations.end(), std::greater<int>());
    
            // then for each index we check if the number of citations is greater than
            // the number we've traversed (guarantees h index)
            for(int i = 0; i < citations.size(); i++){
                if(citations[i] < i + 1)
                    return i; // returns prev
            }
    
            return citations.size();
        }
    };