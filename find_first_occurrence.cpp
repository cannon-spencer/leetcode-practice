class Solution {
    public:
        int strStr(string haystack, string needle) {
            int foundIndex = haystack.find(needle);
            
            if(foundIndex == std::string::npos)
                return -1;
            
            return foundIndex;
        }
    };