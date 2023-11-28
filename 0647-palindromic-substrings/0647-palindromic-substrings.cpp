class Solution {
public:

    bool helper(string str, int i, int j){
        if(i>=j) return true;
        return str[i] == str[j]? helper(str,i+1,j-1):0;
    }
    int isPalindromREC(string &s){
     //Brute Force Recursive T.C = O(n^3), SC = O(1)
        int count = 0;
        int len = s.length();
        for(int start = 0; start<len; start++){
            for(int end = start; end<len; end++){
                
                count+= helper(s,start,end);
            }
        }
        return count;
    }

    //memoisation T.C = O(n^2), SC = O(n^2)
    bool helper(string str, int i, int j,vector<vector<int>> &dp){
        if(i>=j) return true;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = str[i] == str[j]? helper(str,i+1,j-1,dp):0;
    }
    int isPalindromMEM(string &s){
      vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        int len = s.length();
        for(int start = 0; start<len; start++){
            for(int end = start; end<len; end++){
                
                count+= helper(s,start,end,dp);
            }
        }
        return count;
    }
    //memoisation T.C = O(n^2), SC = O(1)
    int expandAroundIndex(string str, int start, int end){
        int count = 0;
        while(start>=0 && end<str.length() && str[start] == str[end]){
            count++;
            start--;
            end++;
        }
        return count;
    }
    int countSubstrings(string s) {
        // int ans = isPalindromREC(s);
        //  int ans = isPalindromMEM(s);
         int count = 0;
        int len = s.length();
        for(int i =0; i<len; i++){
            int oddAns  = expandAroundIndex(s,i,i);
            count += oddAns;
            int evenAns = expandAroundIndex(s,i,i+1);
            count += evenAns;
        }
        return count;
    }
};