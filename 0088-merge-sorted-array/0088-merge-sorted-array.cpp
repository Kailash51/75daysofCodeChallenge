class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right = m - 1;
    int left = n - 1;
    int idx = m + n - 1;

    while (right >= 0 && left >= 0) {
        if (nums1[right] > nums2[left]) {
            nums1[idx--] = nums1[right--];
        } else {
            nums1[idx--] = nums2[left--];
        }
    }

    while (left >= 0) {
        nums1[idx--] = nums2[left--];
    }
        
    }
};