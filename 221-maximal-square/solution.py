class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m, n = len(matrix), len(matrix[0])
        dp = [[0]*n for _ in range(m)]
        for i in range(m): dp[i][0] = int(matrix[i][0])
        for j in range(n): dp[0][j] = int(matrix[0][j])

        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == '0': continue
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1
        res = max([max(l) for l in dp])
        return res ** 2
