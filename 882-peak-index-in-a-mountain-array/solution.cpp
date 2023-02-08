class Solution {
public:
    int peakIndexInMountainArray2(vector<int>& A) {
        for (int i = 0; i < A.size()-2; i++)
            if (A[i+1] - A[i] > 0 && A[i+1] - A[i+2] > 0) return i+1;
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-2;
        while (l < r) {
            int m = (l+r)/2;
            if (A[m] < A[m+1]) l = m+1;
            else r = m;
        }
        return l;
    }
};
