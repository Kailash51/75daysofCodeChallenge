class Solution {
public:
void validParenthesis(int n,  vector<string>& ans, string &output, int open, int close){
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }

    //include open bracket
    if(open >0){
        output.push_back('(');
         validParenthesis(n,ans,output, open-1, close);
         //bt
         output.pop_back();
    }

    //include close bracket
     if(close >open){
        output.push_back(')');
         validParenthesis(n,ans,output, open, close-1);
         //bt
         output.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
       vector<string> allParenthesis;
       int openParen=n;
       int closeParen = n;
       string output = "";
       validParenthesis(n,allParenthesis,output,openParen,closeParen);
       return allParenthesis;
    }
};