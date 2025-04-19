class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int lcp = 0;
            int shortest_str = INT_MAX;
    
            for(int i = 0; i < shortest_str; i++){
    
                char comp = strs[0][i];
                
                for(string str : strs){
    
                    // check for indexing out of bounds
                    if(i == str.size() - 1) 
                        shortest_str = str.size();
    
                    // compare current char to desired
                    if(str[i] != comp)
                        return strs[0].substr(0, lcp);
    
                }
    
                lcp++;
    
            }
    
            return strs[0].substr(0, shortest_str);
    
        }
    };