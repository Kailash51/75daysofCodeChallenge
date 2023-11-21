class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums){
            ans^=x;
        }
        return ans;
    }
    // TC: O(N)
    // SC: O(1)
};