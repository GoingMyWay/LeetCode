class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size(), max_k = k;
        if (n <= 0) {
            return 0;
        }
        if (max_k > n / 2) {
            // 复用之前交易次数 k 没有限制的情况
            return maxProfit_k_inf(prices);
        }

        // base case：
        // dp[-1][...][0] = dp[...][0][0] = 0
        // dp[-1][...][1] = dp[...][0][1] = -infinity
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max_k+1, vector<int>(2, 0)));
        // k = 0 时的 base case
        for (int i = 0; i < n; i++) {
            dp[i][0][1] = INT_MAX;
            dp[i][0][0] = 0;
        }

        for (int i = 0; i < n; i++) 
            for (int k = max_k; k >= 1; k--) {
                if (i - 1 == -1) {
                    // 处理 i = -1 时的 base case
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);     
            }
        return dp[n - 1][max_k][0];
    }

private:
    int maxProfit_k_inf(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
                // base case
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                //   dp[i][1]
                // = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee)
                // = max(dp[-1][1], dp[-1][0] - prices[i] - fee)
                // = max(-inf, 0 - prices[i] - fee)
                // = -prices[i] - fee
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};