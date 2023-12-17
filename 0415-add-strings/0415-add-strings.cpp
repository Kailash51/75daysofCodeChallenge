class Solution {
public:
    void twoStringsSum(string &str1, int str1Size, string &str2, int str2Size, int carry, string & output){
        //base case
        if(str1Size<0 && str2Size<0){
            if(carry !=0){
                output.push_back(carry + '0');
            }
            return;
        }
        int val1 = (str1Size>=0? str1[str1Size]: '0')-'0';
        int val2 = (str2Size>=0? str2[str2Size]: '0')-'0';
        int sum  = val1 + val2 +carry;
        int digit = sum%10;
        carry = sum/10;
        output.push_back(digit +'0');

        twoStringsSum(str1,str1Size-1,str2,str2Size-1,carry,output);

    }

    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        twoStringsSum(num1,num1.length()-1, num2, num2.length()-1,carry, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};