class Solution {
public:
    bool check(vector<int>& nums) {
        int freq = 0;
        int sizeOfNums = nums.size();
        for(int index = 1; index<sizeOfNums; index++){
            if(nums[index-1]>nums[index]){
                freq++;
            }
        }
        if(nums[sizeOfNums-1]>nums[0]){
            freq++;
        }
        return freq<=1;
    }
};