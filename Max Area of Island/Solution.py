class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        max_area = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if visited[row][col] == 0 and grid[row][col] == 1:
                    area = 0
                    returned_area = self.dfs(grid, visited, row, col, area)
                    max_area = max(returned_area, max_area)
        return max_area

    def dfs(self, grid, visited, row, col, area):
        visited[row][col] = 1
        area += 1

        if row+1 < len(grid) and visited[row+1][col] == 0 and grid[row+1][col] == 1:
            area = self.dfs(grid, visited, row+1, col, area)

        if row-1 >= 0 and visited[row-1][col] == 0 and grid[row-1][col] == 1:
            area = self.dfs(grid, visited, row-1, col, area)

        if col-1 >= 0 and visited[row][col-1] == 0 and grid[row][col-1] == 1:
            area = self.dfs(grid, visited, row, col-1, area)

        if col+1 < len(grid[0]) and visited[row][col+1] == 0 and grid[row][col+1] == 1:
            area = self.dfs(grid, visited, row, col+1, area)

        return area
