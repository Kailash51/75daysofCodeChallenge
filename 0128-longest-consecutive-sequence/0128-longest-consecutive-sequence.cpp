class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int numsSize = nums.size();
       int count  = 0;
       int longest = 0;

       unordered_set<int> uniqueElement;
        for(int ind = 0; ind<numsSize; ind++){
        uniqueElement.insert(nums[ind]);
        } 

        for(auto it: uniqueElement){

            if(uniqueElement.find(it-1) == uniqueElement.end()){

                int count = 1;
                int x = it;
                while(uniqueElement.find(x+1)!= uniqueElement.end()){
                    count++;
                    x=x+1;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};