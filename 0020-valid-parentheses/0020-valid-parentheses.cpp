class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;
        char bracket;
        int stringLength = s.length();
        for(int index = 0; index<stringLength; index++){
            bracket = s[index];
            if(bracket == '(' || bracket == '{' || bracket == '['){
                bracketStack.push(bracket);
            }
            else{
                if(bracketStack.empty() || 
                    (bracket == ')' && bracketStack.top() != '(') ||
                    (bracket == '}' && bracketStack.top() != '{') || 
                    (bracket == ']' && bracketStack.top() != '[' )){
                    return false;
                }
                bracketStack.pop(); // otherwise, pop the opening bracket from the stack
            }
        } 
        return bracketStack.empty();// if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
// so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }

};