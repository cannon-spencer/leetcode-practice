class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;

        if(s.size() != t.size()) return false;

        for(char ch: s){
            myMap[ch]++;
        }

        for(char ch: t){
            if(!myMap.count(ch))
                return false;
            
            if(--myMap[ch] < 0)
                return false;
        }

        return true;
    }
};
