
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int len_s = s.size();
//         int len_p = p.size();

//         unordered_map<char,int> p_freq,window_sFreq;
//         vector<int> ans;
//         for(int i=0;i<len_p;i++){
//             p_freq[p[i]]++;
//             window_sFreq[s[i]]++;
//         }
//         if(p_freq==window_sFreq)ans.push_back(0);

//         for(int i=len_p;i<len_s;i++){
//             window_sFreq[s[i]]++;
//             window_sFreq[s[i-len_p]]--;
//             if(window_sFreq[s[i-len_p]]==0) 
//                  window_sFreq.erase(s[i-len_p]);        
//             if(p_freq==window_sFreq)ans.push_back(i-len_p+1);
//         }
//         return ans;

//     }
// };
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pFreq(26, 0);
        vector<int> startIndices;

        for (auto ch:p) pFreq[ch - 'a']++;

        int low = 0;
        vector<int> freq(26, 0);
        for (int high = 0; high < (int)s.length(); high++) {
            int chIdx = s[high] - 'a';
            freq[chIdx]++;
            while (low < (int)s.length() && freq[chIdx] > pFreq[chIdx]) {
                freq[s[low] - 'a']--;
                low++;
            }

            if (freq == pFreq) {
                startIndices.emplace_back(low);
            }
        }

        return startIndices;
    }
};