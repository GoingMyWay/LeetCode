class Solution {
public:
    vector<vector<int>> memo;

    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(k + 1, vector<int>(n + 1, -999));
        return dp(k, n);
    }

    int dp(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;

        if (memo[k][n] != -999) return memo[k][n];

        int res = INT_MAX;
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int broken = dp(k - 1, mid - 1);
            int not_broken = dp(k, n - mid);
            if (broken < not_broken) {
                res = min(res, not_broken + 1);
                left = mid + 1;
            } else {
                res = min(res, broken + 1);
                right = mid - 1;
            }
        }
        memo[k][n] = res;
        return res;
    }
};
