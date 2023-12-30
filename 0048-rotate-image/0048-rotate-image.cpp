class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        

        for(int row = 0; row<rowSize-1; row++){
            for(int col = row+1; col<rowSize; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        for(int row = 0; row<rowSize; row++){
           
             reverse(matrix[row].begin(),matrix[row].end());
            }
        
    }
};