class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        row, col = len(grid), len(grid[0])
        visited = [[-1] * col for _ in range(row)]
        
        for i in range(row):
            for j in range(col):
                if grid[i][j] == '1':
                    visited[i][j] = 0
        
        def dfs(grid, i, j):
            if visited[i][j] == 1: return
            row, col = len(grid), len(grid[0])
            # check its neighbors
            neighbors = []
            if i - 1 >= 0 and grid[i-1][j] == '1':
                neighbors.append((i-1, j))
            if i + 1 <= row -1 and grid[i+1][j] == '1':
                neighbors.append((i+1, j))
            if j - 1 >= 0 and grid[i][j-1] == '1':
                neighbors.append((i, j-1))
            if j + 1 <= col - 1 and grid[i][j+1] == '1':
                neighbors.append((i, j+1))             
            
            visited[i][j] = 1
            for (ni, nj) in neighbors:
                dfs(grid, ni, nj)

        count = 0
        for i in range(row):
            for j in range(col):
                if visited[i][j] == 0: # not visited
                    dfs(grid, i, j)
                    count += 1
        return count