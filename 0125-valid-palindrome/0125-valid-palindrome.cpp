// class Solution {
// public:
    // // brute force, O(N)
//     bool isPalindrome(string s) {
//     int i = 0;
//     string res;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (isalpha(s[i]) || isdigit(s[i]))
//         {
//             if (isupper(s[i]))
//                  res.push_back(tolower(s[i]));
//             else
//                 res.push_back(s[i]);
                
//         }
            
//     }
//     int j = res.size()-1;
//     while(i<j)
//     {
//         if (res[i]!=res[j])
//             return false;
//         i++;
//         j--;
//     }
//     return true;
//     }

    
// };

class Solution {
public:

// Time complexity:O(n)
// Space complexity:O(1)since only use two pointers
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};

