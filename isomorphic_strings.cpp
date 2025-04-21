class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            // push each key val pair to hashmap
            // if it has already been inserted make sure it matches
            unordered_map<char, char> myMap;
    
            // we also need another map to keep track of utilized chars on the output str
            unordered_map<char, bool> inserted;
    
            for(int i = 0; i < s.size(); i++){
                // insert into map if new char for both maps
                if(!myMap.count(s[i]) && !inserted.count(t[i])){
                    myMap[s[i]] = t[i];
                    inserted[t[i]] = 1;
                    continue;
                }
    
                // check for invalid match
                if(myMap[s[i]] != t[i])
                    return false;
            }
    
            return true;
        }
    };