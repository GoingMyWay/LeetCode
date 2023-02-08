class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        self.memo = [[0]*n for _ in range(m)]
        
        def dp(x, y):
            if x == 0 and y == 0:
                return grid[x][y]
            if x < 0 or y < 0:
                return sys.maxsize
            
            if self.memo[x][y] > 0: return self.memo[x][y]
            self.memo[x][y] = min(dp(x-1, y), dp(x, y-1)) + grid[x][y] 
            return self.memo[x][y]

        return dp(m-1, n-1)
