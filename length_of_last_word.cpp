class Solution {
    public:
        int lengthOfLastWord(string s) {
            // index over s in reverse, skip inital whitespace
            int index = s.size() - 1;
    
            // delete trailing whitespace
            while(s[index] == ' ') index--;
            int startIndex = index; // store the real starting index
    
            // find the next whitespace
            while(index >= 0){
                if(s[index] == ' ')
                    break;
                index--;
            }
    
            // return the differene between the start and the following whitespace 
            return startIndex - index;
        }
    };