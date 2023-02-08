class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        max_area = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                max_area = max(self.dfs(grid, row, col, 0), max_area)
        return max_area

    def dfs(self, grid, row, col, area):
        if grid[row][col] == 0:
            return 0
        
        grid[row][col] = 0
        area += 1

        if row+1 < len(grid) and grid[row+1][col] == 1:
            area = self.dfs(grid, row+1, col, area)

        if row-1 >= 0 and grid[row-1][col] == 1:
            area = self.dfs(grid, row-1, col, area)

        if col-1 >= 0 and grid[row][col-1] == 1:
            area = self.dfs(grid, row, col-1, area)

        if col+1 < len(grid[0]) and grid[row][col+1] == 1:
            area = self.dfs(grid, row, col+1, area)

        return area
