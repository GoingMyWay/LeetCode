class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                if (i % 2 == 0) {
                    dp[i] = dp[i] || !dp[i-j];
                }
            }
        }
        return dp[n];
    }
};