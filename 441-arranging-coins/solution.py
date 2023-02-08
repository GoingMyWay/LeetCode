class Solution(object):
    # def arrangeCoins(self, n):
    #     """
    #     :type n: int
    #     :rtype: int
    #     """
    #     count = 1
    #     while True:
    #         n -= count
    #         count += 1
    #         if n < 0:
    #             return count - 2
    #         elif n == 0:
    #             return count - 1

    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        return (int)((2 * n + 0.25)**0.5 - 0.5)
        