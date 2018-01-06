class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        all_count, edge_count = 0, 0
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1:
                    all_count += 1
                    # check vertically and horizontally
                    if r-1 >= 0:
                        if grid[r-1][c] == 1:
                            edge_count += 1
                    
                    if r+1 <= len(grid)-1:
                        if grid[r+1][c] == 1:
                            edge_count += 1
                    
                    if c-1 >= 0:
                        if grid[r][c-1] == 1:
                            edge_count += 1
                    
                    if c+1 <= len(grid[0])-1:
                        if grid[r][c+1] == 1:
                            edge_count += 1
        return all_count*4 - edge_count
        