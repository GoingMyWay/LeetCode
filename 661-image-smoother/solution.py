class Solution(object):
    def imageSmoother(self, M):
        """
        :type M: List[List[int]]
        :rtype: List[List[int]]
        """
        from copy import deepcopy as copy
        res = copy(M)
        row = len(M)
        col = len(M[0]) if row else 0
        for i in xrange(row):
            for j in xrange(col):
                neighbors = [
                    M[_i][_j]
                    for _i in (i-1, i, i+1)
                    for _j in (j-1, j, j+1)
                    if 0 <= _i < row and 0 <= _j < col
                ]
                res[i][j] = sum(neighbors) / len(neighbors)
        return res