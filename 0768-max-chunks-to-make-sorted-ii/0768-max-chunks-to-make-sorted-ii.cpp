class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int arrSize = arr.size();
        int ans = 0;
        vector<int> leftMax(arrSize);
        vector<int> rightMin(arrSize);
        leftMax[0] = arr[0];
        rightMin[arrSize-1] = arr[arrSize-1];
        for(int ind  = 1; ind< arrSize; ind++){
            leftMax[ind] = max(leftMax[ind-1], arr[ind]);
        }

        for(int ind = arrSize-2; ind>=0; ind--){
            rightMin[ind] = min(rightMin[ind+1], arr[ind]);
        }

        for(int ind  = 0; ind<arrSize-1; ind++){
            if(leftMax[ind] <= rightMin[ind+1]) ans++;
        }
        return ans+1;
        
    }
};