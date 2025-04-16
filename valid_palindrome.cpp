class Solution {
    public:
        bool isPalindrome(string s) {
            int startPointer = 0;
            int endPointer = s.size() - 1;
    
            // while the pointers havent met
            while(startPointer < endPointer){
                // find valid char for start pointer
                while(startPointer < endPointer && !isalnum(s[startPointer])){
                    startPointer++;
                }
    
                // find valid char for end pointer
                while(startPointer < endPointer && !isalnum(s[endPointer])){
                    endPointer--;
                }
    
                char startChar = tolower(s[startPointer]);
                char endChar = tolower(s[endPointer]);
    
                if(startChar != endChar)
                    return false;
              
                startPointer++;
                endPointer--;
                
            }
    
            return true;
        }
    };