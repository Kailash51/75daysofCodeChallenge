class Solution {
public:

void PermutationHelper(vector<int>& arr, vector<vector<int>>& ans, int start) {
    if (start == arr.size()) {
        ans.push_back(arr);
        return;
    }
    unordered_map<int,bool> visited_umap;
    
    for (int ind = start; ind < arr.size(); ind++) {

        if(visited_umap.find(arr[ind]) != visited_umap.end())
    continue;
        visited_umap[arr[ind]] = true;
        swap(arr[ind], arr[start]);
        PermutationHelper(arr, ans, start + 1);
        //backtrack
        swap(arr[ind], arr[start]);
    }
}


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
    PermutationHelper(nums, ans, 0);
    return ans;
    }
};