class Solution {
public:
    int myAtoi(string s) {
        // TC O(n) SC O(1)
        int index = 0;
        int sign = +1;
        long desiredAnswer = 0;
        if(s.length() == 0) return 0;
        // step 1
        while(index<s.length() && s[index] ==' ') {
            index++;
        }
        s = s.substr(index);// i ->last eleminate leading space
        if(s[0] == '-') sign = -1;
        index = (s[0] == '+' || s[0] == '-')? 1:0;
         

        while(index<s.length()){
            if(s[0] == ' ' || !isdigit(s[index])) break;
            desiredAnswer = desiredAnswer*10 + s[index] -'0';
            if(sign == -1 && -1*desiredAnswer < INT_MIN) return INT_MIN;
            if(sign == 1 && desiredAnswer > INT_MAX) return INT_MAX;
            ++index;
        }
        return (int)(sign*desiredAnswer);
    }
        
        
};