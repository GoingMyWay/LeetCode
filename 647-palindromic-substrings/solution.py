class Solution:
    def countSubstrings(self, s: str) -> int:
        ans = 0
        n = len(s)
        if n <= 0: return ans
        
        dp = [[False]*n for _ in range(n)]

        # basecase 1: s[i] = s[i]
        for i in range(n):
            dp[i][i] = True
            ans += dp[i][i]
        
        # basecase 2: two consective char
        for i in range(n-1):
            dp[i][i+1] = (s[i] == s[i+1])
            ans += dp[i][i+1]
        
        for _len in range(3, n+1):
            i = 0
            j = i + _len - 1
            while j < n:
                dp[i][j] = dp[i+1][j-1] and (s[i] == s[j])
                ans += dp[i][j]
                i += 1
                j += 1
        return ans
