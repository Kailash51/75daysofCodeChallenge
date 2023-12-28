class Solution {
public:
    
    vector<int> pascalTriangle(int row){
        long long ans = 1;
        vector<int> rowAns;
        rowAns.push_back(1);
        for(int col = 1; col<row; col++){
            ans *= row-col;
            ans /=col;
            rowAns.push_back(ans);
        }
        return rowAns;
    }
    vector<vector<int>> generate(int numRows) {
        // int n = numRows[].size();
        vector<vector<int>> ans;
        for(int index = 1; index<=numRows; index++){
            ans.push_back(pascalTriangle(index));
        } 
        return ans;
        
    }
};