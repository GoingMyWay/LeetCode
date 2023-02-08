class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        dp = [0, 10] + [9]*(n-1)
        for i in xrange(2, n+1):
            if i == 2:
                dp[i] = 9 * (10-i+1)
            else:
                dp[i] = dp[i-1] * (10-i+1)
        return sum(dp)
