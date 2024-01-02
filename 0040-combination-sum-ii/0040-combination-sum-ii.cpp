class Solution {
public:

void canbinationSum_helper(vector<int>& candidates, int key, vector<int> &v, vector<vector<int>> &ans, int index){
    if(key== 0){
        ans.push_back(v);
        return;
    }

    if(key < 0){
        return;
    }

    for(int i = index; i<candidates.size(); i++){
        if(i>index && candidates[i] == candidates[i-1]){
            continue;
        }
        v.push_back(candidates[i]);
        canbinationSum_helper(candidates,key-candidates[i], v, ans, i+1);
        v.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<vector<int>> ans;
        vector<int> v;
        canbinationSum_helper(candidates, target, v, ans, 0);
        return ans;
    }
};