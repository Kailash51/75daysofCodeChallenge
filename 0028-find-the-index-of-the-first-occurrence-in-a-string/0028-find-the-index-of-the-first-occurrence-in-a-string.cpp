class Solution {
public:
    int strStr(string haystack, string needle) {
    // Time complexity:O((n*m)  Space complexity:O(1)

        int lengthOfNeedle = needle.length();
        int lengthOfHaystack = haystack.length();
        for(int index1 = 0; index1<=lengthOfHaystack-lengthOfNeedle; index1++){
            for(int index2 = 0; index2<lengthOfNeedle; index2++){
                if(needle[index2] != haystack[index1+index2]){
                    break;
                }

                if(index2 == lengthOfNeedle-1){
                    return index1;
                }
            }
        }
        return -1;
    }
};

// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//     //TC O(n) SC O(1)
//     return haystack.find(needle);
//     }
// };