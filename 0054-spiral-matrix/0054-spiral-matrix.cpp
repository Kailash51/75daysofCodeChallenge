class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
       int  m = matrix.size(); // m no. of equal to row
       int  n = matrix[0].size(); // n no.of qual to colom

        int startingCol = 0;
        int endingCol = n-1;
        int startingRow =0;
        int endingRow = m-1;
         int totalElement = n*m;


        int count = 0;
        //starting row 
            while(count <totalElement ){
                for(int i=startingCol; i<=endingCol && count <totalElement; i++ ){
                 ans.push_back(matrix[startingRow][i]);
                 count++;
                }
                startingRow++;

                //ending col
                for(int i= startingRow; i<=endingRow &&count <totalElement; i++){
                    ans.push_back(matrix[i][endingCol]);
                    count++;

                }
                endingCol--;

                //ending row

                for(int i = endingCol; i>=startingCol && count <totalElement; i--){
                    ans.push_back(matrix[endingRow][i]);
                    count++;
                }
                endingRow--;

                //stating col

                for(int i = endingRow ; i>=startingRow && count <totalElement; i--){
                    ans.push_back(matrix[i][startingCol]);
                    count++;
                } 
                startingCol++;
            }
            return ans;
    }
};