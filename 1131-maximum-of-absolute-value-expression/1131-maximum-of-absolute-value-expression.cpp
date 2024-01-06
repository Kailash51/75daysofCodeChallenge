class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = min(arr1.size(), arr2.size()), i = 0;
        int max_val1 = INT_MIN, min_val1 = INT_MAX, max_val2 = INT_MIN, min_val2 = INT_MAX, max_val3 = INT_MIN, min_val3 = INT_MAX, max_val4 = INT_MIN, min_val4 = INT_MAX; 
        while (i<n) {
            int val1 = arr1[i] + arr2[i] + i;
            int val2 = arr1[i] + arr2[i] - i;
            int val3 = arr1[i] - arr2[i] + i;
            int val4 = arr1[i] - arr2[i] - i;
            max_val1 = max(max_val1, val1);
            max_val2 = max(max_val2, val2);
            max_val3 = max(max_val3, val3);
            max_val4 = max(max_val4, val4);
            min_val1 = min(min_val1, val1);
            min_val2 = min(min_val2, val2);
            min_val3 = min(min_val3, val3);
            min_val4 = min(min_val4, val4);
            i++;
        }
        int res = max(max_val1-min_val1, max (max_val2-min_val2, max (max_val3-min_val3, max_val4-min_val4)));
        return res;
    }
};