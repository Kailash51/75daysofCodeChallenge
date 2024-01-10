class Solution {
public:

bool validDistribute(vector<int>& nums, vector<int>& quantity,vector<int> storeCounts, int ithCustomer){
    //base case
    if(ithCustomer==quantity.size()) return true;

    for(int ind =0;  ind<storeCounts.size(); ind++){
        if(storeCounts[ind] >= quantity[ithCustomer]){
            storeCounts[ind] -= quantity[ithCustomer];
            if(validDistribute(nums, quantity, storeCounts, ithCustomer+1)){
                return true;
            }
            storeCounts[ind] += quantity[ithCustomer];
        }
    }
    return false;

}
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int , int> countingMap;
        vector<int> storeCounts;
        for(auto num:nums){
            countingMap[num]++;
        }
        for(auto val:countingMap){
            storeCounts.push_back(val.second);
        }
        //sort in 
        sort(quantity.rbegin(), quantity.rend());
        return validDistribute(nums,quantity,storeCounts,0);

    }
};