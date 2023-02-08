class Solution(object):
    def minInsertions(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s) - self.longestPalindromeSubseq(s)
    
    def longestPalindromeSubseq(self, s):
        n = len(s)
        dp = [[0]*n for _ in range(n)]
        for i in range(n): dp[i][i] = 1

        for i in reversed(range(n)):
            for j in range(i+1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i+1][j-1] + 2
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1])
        return dp[0][n-1]
