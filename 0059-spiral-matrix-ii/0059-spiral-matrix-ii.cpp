#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n, 0));

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n-1;
        int endingCol = n-1;
        int totalElement = n*n;

        // if(n==1){
        //    return matrix.push_back({1});
        // }

        int count = 1;
        while(count<=totalElement){
            // top
            for(int i=startingCol; i<=endingCol && count <=totalElement; i++ ){
                matrix[startingRow][i] = count++;
            }
                startingRow++;
            

            //right
            for(int  i = startingRow; i<=endingRow &&count <=totalElement; i++){
                matrix[i][endingCol] = count++;
            }
            endingCol--;

            for(int i=endingCol; i>=startingCol && count <=totalElement; i-- ){
                matrix[endingRow][i] = count++;
            }
            endingRow--;

            for(int  i = endingRow; i>=startingRow &&count <=totalElement; i--){
                matrix[i][startingCol] = count++;
            }
            startingCol++;
        }
        return matrix;

    }
};