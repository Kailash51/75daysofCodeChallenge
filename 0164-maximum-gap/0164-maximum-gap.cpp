class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int currDiff;
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        for(int ind = 1; ind<nums.size(); ind++){
            currDiff = nums[ind]-nums[ind-1];
            maxDiff= max(maxDiff,currDiff);
        }

        return maxDiff;
        
    }
};