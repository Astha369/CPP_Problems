class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i = n + m - 1, j = m - 1, k = n - 1;
    while(j >= 0 || k >= 0) {
        if(j >= 0 && (k < 0 || nums1[j] >= nums2[k])) nums1[i--] = nums1[j--];
        if(k >= 0 && (j < 0 || nums1[j] < nums2[k])) nums1[i--] = nums2[k--];
    }
    }
};