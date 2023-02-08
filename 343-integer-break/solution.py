class Solution:
    def integerBreak(self, n: int) -> int:
        slices_nums = [i for i in range(1, n+1)]
        
        dp = [1] * (n+1)
        for i in range(3, n+1):
            for k in range(1, i):
                dp[i] = max(dp[i], dp[i-k]*k, k*(i-k))
        return dp[-1]
