// class Solution {
// public:

//     int solve(vector<vector<int>>& obstacleGrid, int n, int m, int i, int j) {
//     // Base case: if the current cell is an obstacle or out of bounds, return 0
//     if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
//         return 0;
//     }

//     // Base case: if we reached the bottom-right cell, return 1 (one valid path found)
//     if (i == n - 1 && j == m - 1) {
//         return 1;
//     }

//     // Recursive case: move right + move down
//     int rightPaths = solve(obstacleGrid, n, m, i, j + 1);
//     int downPaths = solve(obstacleGrid, n, m, i + 1, j);

//     // Return the total number of valid paths
//     return rightPaths + downPaths;
// }

// int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//     int n = obstacleGrid.size();
//     int m = obstacleGrid[0].size();

//     return solve(obstacleGrid, n, m, 0, 0);
// }

// };

class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid, int n, int m, int i, int j,vector<vector<int>>&memo) {
    // Base case: if the current cell is an obstacle or out of bounds, return 0
    if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
        return 0;
    }

    // Base case: if we reached the bottom-right cell, return 1 (one valid path found)
    if (i == n - 1 && j == m - 1) {
        return 1;
    }
    if(memo[i][j] != -1) return memo[i][j];

    // Recursive case: move right + move down
    int rightPaths = solve(obstacleGrid, n, m, i, j + 1,memo);
    int downPaths = solve(obstacleGrid, n, m, i + 1, j,memo);

    // Return the total number of valid paths
    memo[i][j] =  rightPaths + downPaths;
    return memo[i][j];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> memo(n+1, vector<int>(m+1,-1));
    return solve(obstacleGrid, n, m, 0, 0,memo);
}

};