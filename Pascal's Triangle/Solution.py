class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        result = []
        for i in xrange(numRows):
            if i == 0:
                result.append([1])
            elif i == 1:
                result.append([1, 1])
            else:
                res = [result[-1][i]+result[-1][i+1] for i in range(len(result[-1])-1)]
                result.append([1] + res + [1])
        return result
