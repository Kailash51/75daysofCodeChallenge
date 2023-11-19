class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Brute

        // int size = s.length();
        // int ans = 0;
        // for(int start = 0; start<size; start++){
        //     set<int> st;
        //     for(int end = start; end<size; end++){
        //         st.insert(s[end]);
        //         if(st.size() == end-start+1){
        //             ans = max(ans,end-start+1);
        //         }
        //     }
        // }
        // return ans;
        // T.C = O(n^2)
        // S.C =her space complexity might be O(m), where m is the number of unique characters in the string

        // Better

        // unordered_map<char, int> track;
        // int size = s.length();
        // int ans = 0;

        // int slow = 0; int fast = 0;
        // while(fast<size){
        //     track[s[fast]]++;
        //     if(track.size() == fast-slow+1){
        //         ans = max(ans, fast-slow+1);
        //         fast++;
        //     }
            

        //     else if(track.size() < fast-slow+1){
        //         while(track.size()<fast-slow+1){
        //            track[s[slow]]--;
        //             if(track[s[slow]] ==0){
        //                 track.erase(s[slow]);
        //             }
        //             slow++;
        //         }
        //         fast++;
        //     }
        // }
        // return ans;

        // Time Complexity: O(n)
        // space complexity of O(m), where m is the number of unique characters.

        // Optimal 
        vector<int> freq(256, 0);
        int size = s.length();
        int ans = 0;

        int slow = 0; int fast = 0;
        while(fast<size){
            freq[s[fast]]++;
            if(freq[s[fast]] == 1){
                ans = max(ans, fast-slow+1);
                fast++;
            }
            

            else if(freq[s[fast]] > 1){
                while(freq[s[fast]] > 1){
                   freq[s[slow]]--;
                   slow++;
                }
                ans = max(ans, fast-slow+1);
                fast++;
            }
        }
        return ans;

        // Time Complexity: O(n)
        // space complexity of O(1), where m is the number of unique characters.

        
    }
};