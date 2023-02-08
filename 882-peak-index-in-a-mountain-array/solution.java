class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int l = 0, r = A.length - 2;
        while (l < r) {
            int m = (l+r) / 2;
            if (A[m] < A[m+1]) l = m+1;
            else r = m;
        }
        return r;
    }
}