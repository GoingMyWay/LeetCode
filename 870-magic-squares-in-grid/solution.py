class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def magic(a, b, c, d, e, f, g, h, i):
            if set([a, b, c, d, e, f, g, h, i]) != set(range(1, 10)):
                return False
            return a+b+c == d+e+f == g+h+i == a+d+g == b+e+h == c+f+i == a+e+i == c+e+g == 15
        
        count = 0
        for i in range(len(grid)-2):
            for j in range(len(grid[0])-2):
                if grid[i+1][j+1] != 5:
                    continue
                if magic(grid[i][j], grid[i][j+1], grid[i][j+2], 
                         grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                         grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]):
                    count += 1
        return count
    