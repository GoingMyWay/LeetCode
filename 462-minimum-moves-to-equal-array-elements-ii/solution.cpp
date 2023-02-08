class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int median = findMedian(nums, nums.size());
        int res = 0;
        for (auto v: nums) {
            res += abs(v - median);
        }
        return res;
    }

    int findMedian(vector<int> a, int n) {
        if (n % 2 == 0) {
            nth_element(a.begin(), a.begin() + n / 2, a.end());
            nth_element(a.begin(), a.begin() + (n - 1) / 2, a.end());
            return (a[(n - 1) / 2] + a[n / 2]) / 2;
        } else {
            nth_element(a.begin(), a.begin() + n / 2, a.end());
            return a[n / 2];
        }
    }
};
