class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int res = 0, i;
        for(i=0; i<nums.size(); i++){
            res = res ^ nums[i] ^ i;
        }
        return res^i;
    }
};