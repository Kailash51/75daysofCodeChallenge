class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int r = m-1;
        double results = 1;

        for(int ind = 1; ind<=r; ind++){
            results = results* (N-r+ind)/ind;
        }
        return results;
    }
};