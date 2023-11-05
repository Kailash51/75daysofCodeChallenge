class Solution {
public:

    // // Brute force t.c = O(n^2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j=i+1; j<nums.size(); j++){
    //             if(nums[i] + nums[j] == target){
    //                 return {i ,j}; 
    //             }
    //         }
    //     }
    //     return {};
        
    // }

     // Otimal t.c= O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,int> mp;
        for(int i =0; i<nums.size(); i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(mp.find(moreNeeded)==mp.end()){
                mp[num] = i; 
            }
            else{
                return {mp[moreNeeded],i};//here mp[moreneeded] give indices of     moreNeeded
            }
        }
    
        return {-1,-1};
        
    }
};