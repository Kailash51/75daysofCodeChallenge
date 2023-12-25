class Solution {
public:
    
    void possibleSubsetsHelper(vector<int>& arr,int index, vector<int> subset,vector<vector<int>> &powerset, int arraySize){
        if(index == arraySize) return powerset.push_back(subset);
        
        
        // pick
        subset.push_back(arr[index]);
        possibleSubsetsHelper(arr,index+1,subset,powerset,arraySize);
        subset.pop_back();
        //notpick
        while(index+1<arraySize && arr[index] == arr[index+1]){
            index++;
        }
        possibleSubsetsHelper(arr,index+1,subset,powerset,arraySize);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        int arraySize = nums.size();
        sort(nums.begin(), nums.end());
        possibleSubsetsHelper(nums,0,subset,powerset,arraySize);
        return powerset;
    }
};