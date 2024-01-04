class Solution {
public:


    void uniquePermutationHelper(vector<int>& arr, vector<vector<int>>& ans, int start) {
    if (start == arr.size()) {
        ans.push_back(arr);
        return;
    }

    for (int ind = start; ind < arr.size(); ind++) {
        swap(arr[ind], arr[start]);
        uniquePermutationHelper(arr, ans, start + 1);
        //backtrack
        swap(arr[ind], arr[start]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    uniquePermutationHelper(nums, ans, 0);
    return ans;
}

};