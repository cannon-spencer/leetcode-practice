class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> myMap;
    
            for(char ch : magazine){
                myMap[ch]++;
            }
    
            for(char ch : ransomNote){
                if(--myMap[ch] < 0)
                    return false;
            }
    
            return true;
        }
    };