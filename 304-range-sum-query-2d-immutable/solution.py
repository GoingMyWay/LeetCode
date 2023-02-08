class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        m, n = len(matrix), len(matrix[0])
        self.presum = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                self.presum[i][j] = self.presum[i-1][j] + \
                                    self.presum[i][j-1] + \
                                    matrix[i-1][j-1] - \
                                    self.presum[i-1][j-1]
    
    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.presum[row2+1][col2+1] - \
                self.presum[row2+1][col1] - \
                self.presum[row1][col2+1] + \
                self.presum[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)