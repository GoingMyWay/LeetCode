class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit, i, length = 0, 1, len(prices)
        while i < length:
            if prices[i] > prices[i-1]:
                max_profit += prices[i] - prices[i-1]
            i += 1
        return max_profit
            