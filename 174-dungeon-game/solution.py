class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        self.m, self.n = len(dungeon), len(dungeon[0])
        self.memo = [[-1]*self.n for _ in range(self.m)]
        self.grid = dungeon
        return self.dp(0, 0)

    def dp(self, i: int, j: int) -> int:
        if (i == self.m - 1 and j == self.n - 1):
            return 1 if self.grid[i][j] >= 0 else -self.grid[i][j]+1
        
        if (i == self.m or j == self.n): return sys.maxsize
        if self.memo[i][j] != -1: return self.memo[i][j]

        res = min(self.dp(i, j+1), self.dp(i+1, j)) - self.grid[i][j]
        self.memo[i][j] = 1 if res <=0 else res
        return self.memo[i][j]
