class Solution {
public:
    // first approach using extra space to just parse the words
    // then store in a new string
    string reverseWords(string s) {
        std::string currentWord;
        std::stack<std::string> myStack;

        for(char ch: s){
            if(ch == ' '){
                // add element to stack
                if(!currentWord.empty()){
                    myStack.push(currentWord);
                    currentWord.clear();
                }
                continue;
            } 
            
            currentWord += ch;
        }

        // push the last word
        if(!currentWord.empty())
            myStack.push(currentWord);

        // empty stack out into a new string
        std::string out;
        while(!myStack.empty()){
            out += myStack.top();
            myStack.pop();
            if(!myStack.empty()) out += " ";
        }

        return out;
    }
};
