class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;

        for(auto it: nums){
            if(cnt1 == 0 && ele2 != it){
                cnt1 = 1;
                ele1 = it;
            }
           else if(cnt2 == 0 && ele1 != it){
                cnt2 = 1;
                ele2 = it;
            }
            else if(ele1 == it) cnt1++;
            else if(ele2 == it) cnt2++;
            else{
                cnt1--,cnt2--;
            }
        }

        vector<int> list;
        

        int count1 = 0, count2 = 0;
        for(auto it: nums){
            if(it== ele1) count1++;
            if(it==ele2) count2++;
        }

        int mini = int(nums.size()/3)+1;
        if(count1>=mini) list.push_back(ele1);
        if(count2>=mini) list.push_back(ele2);

        return list;
    }
};