class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        self.memo = [[0]*n for _ in range(m)]
        def dp(x, y):
            if x == 0 and y == 0:
                return 1
            if x < 0 or y < 0:
                return 0
            
            if self.memo[x][y] > 0: return self.memo[x][y]
            self.memo[x][y] = dp(x-1, y) + dp(x, y-1)
            return self.memo[x][y]
                    
        return dp(m-1, n-1)
