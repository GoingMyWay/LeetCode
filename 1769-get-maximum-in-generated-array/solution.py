class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        if n == 0: return 0
        dp = [0] * (n+1)
        dp[0], dp[1] = 0, 1
        res = max(dp[0], dp[1])
        for i in range(1, n+1):
            if 2 <= 2*i <= n:
                dp[2*i] = dp[i]
                res = max(res, dp[2*i])
            if 2 <= 2*i+1 <= n:
                dp[2*i+1] = dp[i] + dp[i+1]
                res = max(res, dp[2*i+1])
        return res
