class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Brute
        // TC: O(N)
        // SC: O(N)

        // vector<int> ans;

        // unordered_map<int , int> freq;
        // int size = nums.size();
        // for(int val = 0; val<size; val++){
        //     freq[nums[val]]++;
        // }    
        // for(auto x:freq){
        //     if(x.second == 1){
        //        ans.push_back(x.first);
        //     }
        // }
        
        //     return ans;
       
        int xorResult = 0;

        // XOR all numbers to find the XOR of the two distinct numbers
        for (int num : nums) {
            xorResult ^= num;
        }

        // Find the rightmost set bit
         int mask = 1;
        while ((mask & xorResult) == 0) {
        mask <<= 1;
    }

        int num1 = 0, num2 = 0;

        // Separate the numbers based on the rightmost set bit
        for (int num : nums) {
            if ((num & mask) != 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }

    
};