class Solution {
    public:
        bool isValid(string s) {
            std::stack<char> myStack;
    
            for(char ch : s){
                // if opening bracket, push to stack
                if(ch == '(' || ch == '{' || ch == '[' )
                    myStack.push(ch);
    
                // if closing bracket, pop from stack (must match type or invalid)
                else {
                    if(myStack.empty()) 
                        return false;
                        
                    char topBracket = myStack.top();
                    if(topBracket == '(')
                        topBracket = ')';
                    else if(topBracket == '{')
                        topBracket = '}';
                    else
                        topBracket = ']';
    
                    if(ch != topBracket)
                        return false;
                    
                    myStack.pop();
                }
            }
    
            return myStack.empty();
        }
    };