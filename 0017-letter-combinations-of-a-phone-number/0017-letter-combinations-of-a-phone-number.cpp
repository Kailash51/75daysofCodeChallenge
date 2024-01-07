class Solution {
public:

void letterCombinationsHelper(string digits,  unordered_map<int , string> digitToLetterMap,vector<string> &ans, string output, int index){
    if(digits.length()==0){
        return;
    }
    if(index == digits.length()){
        ans.push_back(output);
        return;
    }
    // ek case solve
    char digitChar = digits[index];
    int digitInteger = (digitChar-'0');
    string value = digitToLetterMap[digitInteger];

    for(int ind = 0; ind<value.length(); ind++){
        output.push_back(value[ind]);
        letterCombinationsHelper(digits,digitToLetterMap,ans,output,index+1);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        unordered_map<int , string> digitToLetterMap;
        digitToLetterMap[2] = "abc";
        digitToLetterMap[3] = "def";
        digitToLetterMap[4] = "ghi";
        digitToLetterMap[5] = "jkl";
        digitToLetterMap[6] = "mno";
        digitToLetterMap[7] = "pqrs";
        digitToLetterMap[8] = "tuv";
        digitToLetterMap[9] = "wxyz";

        letterCombinationsHelper(digits, digitToLetterMap,ans, output,0);
        return ans;




    }
};