class Solution {
public:
    
   long long NthPascalTriangle(int n, int row){
    if (row == 0) return 1; // Base case: First element of each row is 1

    long long ans = 1;
    for(int i = 1; i <= row; ++i){
        ans *= (n - i + 1);
        ans /= i;
    }
    return ans;
}

vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1);

    for(int col = 0; col <= rowIndex; ++col){
        ans[col] =(NthPascalTriangle(rowIndex, col));
    }
    return ans;
}

};