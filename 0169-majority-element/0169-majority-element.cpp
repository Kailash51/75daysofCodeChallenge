class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mostOcurre = 0;
        int count = 0;
        int sizeOfNums =  nums.size();
      
        for(auto it: nums){
            if(count == 0){
                mostOcurre = it;
            }

            if(it == mostOcurre){
                count++;
            }else{
                count--;
            }
        }
        return mostOcurre;
        
    }
};