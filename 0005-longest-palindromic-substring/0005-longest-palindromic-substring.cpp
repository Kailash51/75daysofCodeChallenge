// class Solution {
// public:
// //Brute Force  REcursion TC O(n^3) , SC O(n)
// bool isPalindrome(string &stringValue, int pointer1, int pointer2){
//     if(pointer1>=pointer2){
//         return true;
//     }
//     if(stringValue[pointer1] == stringValue[pointer2]){
//         isPalindrom(stringValue, pointer1++, pointer2--);
//     }
    
    
//     return false;
    
// }
//     string longestPalindrome(string s) {   
//         int lenghtOfString = s.length();
//         int maximumLengthOfString = INT_MIN;
//         int initialPoint = 0;
//         for(int index1 =0; index1<lenghtOfString; index1++){
//             for(int index2= index1; index2<lenghtOfString; index2++){
//                 if(isPalindrome(s, index1, index2) == true){
//                     if(index2-index1+1>maximumLengthOfString){
//                         maximumLengthOfString = index2-index1+1;
//                         initialPoint = index1;
//                     }
//                 }
//             }
//         }
//         return s.substr(initialPoint,maximumLengthOfString);
        
//     }
// };



// class Solution {
// public:
// //Memoisation  TC O(n^2) , SC O(n^2) =~ O(1)
// bool isPalindrome(string &stringValue, int pointer1, int pointer2, vector<vector<int>> &memo){
//     if(pointer1 >= pointer2){
//         return true;
//     }
//     if(memo[pointer1][pointer2] != -1){
//         return memo[pointer1][pointer2];
//     }
//     if(stringValue[pointer1] == stringValue[pointer2]){
//         memo[pointer1][pointer2] = isPalindrome(stringValue, ++pointer1, --pointer2, memo);
//     } else {
//         memo[pointer1][pointer2] = false;
//     }
    
//     return memo[pointer1][pointer2];
// }
//     string longestPalindrome(string s) {  
//          int lenghtOfString = s.length();
//         vector<vector<int>> memo(1001, vector<int>(1001,-1)); 
//         int maximumLengthOfString = INT_MIN;
//         int initialPoint = 0;
//         for(int index1 =0; index1<lenghtOfString; index1++){
//             for(int index2= index1; index2<lenghtOfString; index2++){
//                 if(isPalindrome(s, index1, index2,memo) == true){
//                     if(index2-index1+1>maximumLengthOfString){
//                         maximumLengthOfString = index2-index1+1;
//                         initialPoint = index1;
//                     }
//                 }
//             }
//         }
//         return s.substr(initialPoint,maximumLengthOfString);
        
//     }
// };

// Expand Around Center : [TC : O(n^2) , SC : O(1)
        
//     }
// };



class Solution {
    public:
    int maximumLengthOfString = INT_MIN;
    int initialPoint = 0;
    // Expand Around Center : [TC : O(n^2) , SC : O(1)
    void isPalindrome(string &stringValue, int pointer1, int pointer2){
        while(pointer1>=0 && pointer2<stringValue.length() && stringValue[pointer1] == stringValue[pointer2]){
            if(pointer2-pointer1+1>maximumLengthOfString){
                maximumLengthOfString = pointer2-pointer1+1;
                initialPoint = pointer1;
            }
            pointer1--;
            pointer2++;
        }
        
    }
    string longestPalindrome(string s) {  
        int lenghtOfString = s.length();
        if(lenghtOfString<=1)
            return s;
       
        for(int index1 =0; index1<lenghtOfString; index1++){
            //STRING OF ODD LENGTH
           isPalindrome(s, index1, index1);
             // STRING OF EVEN LENGTH
           isPalindrome(s, index1, index1+1);
      
        }
        return s.substr(initialPoint,maximumLengthOfString);
        
    }
};