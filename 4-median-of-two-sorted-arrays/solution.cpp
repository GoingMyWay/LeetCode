class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        //第一个数组一定是短的，这是因为 我们要保证i和j都是大于0的数。因为l<=r的限制，那么如果i=m的时候，j就一定为负数了。
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0, r = m; //A中元素有m个，有m+1种划分方法。这里的i表示leftA有几个元素。
        int median1 = 0, median2 = 0;
        while (l <= r) {
            int i = (l+r) / 2;
            int j = (m+n+1) / 2 - i;
            int leftA = (i > 0 ? nums1[i-1]: INT_MIN);
            int rightA = (i < m ? nums1[i]: INT_MAX);
            int leftB = (j > 0 ? nums2[j-1]: INT_MIN);
            int rightB = (j < n ? nums2[j]: INT_MAX);
            if (leftA <= rightB) {
                median1 = max(leftA, leftB);
                median2 = min(rightA, rightB);
                l = i + 1;
            } else {
                r = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};
