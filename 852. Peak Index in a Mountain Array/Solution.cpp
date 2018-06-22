class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for (int i = 0; i < A.size()-2; i++)
            if (A[i+1] - A[i] > 0 && A[i+1] - A[i+2] > 0) return i+1;
    }
};

