class Solution {
public:
    int characterReplacement(string s, int k) {
        int lengthOfString = s.length();
        int maxFrequency = 0, maxLength = 0, startPointer = 0;
        unordered_map<char, int> frequencyCount;
        for(int endPointer = 0; endPointer<lengthOfString; endPointer++){
            frequencyCount[s[endPointer]]++;
            maxFrequency = max(maxFrequency,frequencyCount[s[endPointer]]);

            // len-maxfreq<=k
            while((endPointer-startPointer+1) - maxFrequency>k){
                //shrink
                frequencyCount[s[startPointer]]--;
                startPointer++;
            }
            maxLength = max(maxLength,endPointer-startPointer+1);
        }
        return maxLength;
    }
};