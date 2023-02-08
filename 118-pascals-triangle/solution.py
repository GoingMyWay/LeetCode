class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        result = [[1]]
        for _ in xrange(1, numRows):
            result.append(map(lambda x, y: x+y, result[-1]+[0], [0]+result[-1]))
        
        return result
