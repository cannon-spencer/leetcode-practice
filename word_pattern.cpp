class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int j = 0;

        unordered_map<char, string> forward;
        unordered_map<string, char> backward;
        vector<string> words;

        // extract all the words from s and place into array
        while(j < s.size()){
            string nextWord;
            while (j < s.size() && s[j] != ' ') {
                nextWord += s[j++];
            }
            j++; // we've hit a space so skip it
            words.push_back(nextWord);
        }

        // if pattern doesnt equal number of words we reject
        if(pattern.size() != words.size())
            return false;

        // push each to forward/backward tracing hash map
        for(int i = 0; i < pattern.size(); i++){

            int ch = pattern[i];
            string nextWord = words[i];

            // if char is stored already, its value from the map
            // better match the current word
            if(forward.count(ch)) {
                if(forward[ch] != nextWord)
                    return false;
            }

            // we must also check to make sure the current word
            // does not map to anything else becides the current letter
            if(backward.count(nextWord)){
                if(backward[nextWord] != ch)
                    return false;
            }

            forward[ch] = nextWord;
            backward[nextWord] = ch;
            
        }

        return true;
    }
};
