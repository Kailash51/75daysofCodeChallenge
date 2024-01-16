class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arrSize = arr.size();
        int ans = 0;
        int currMax = arr[0];
        for(int ind = 0; ind<arrSize; ind++){
            currMax = max(currMax, arr[ind]);
            if(currMax == ind){
                ans++;
            }
        }
        return ans;
        
    }
};