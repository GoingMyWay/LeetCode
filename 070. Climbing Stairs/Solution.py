class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        first, second = 1, 2
        for i in range(3, n+1):
            first, second = second, second + first
        return n if n == 1 else second 
