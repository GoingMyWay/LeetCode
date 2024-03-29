class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        :type prices: List[int]
        :rtype: int
        """
        min_price = sys.maxsize
        max_profit = 0
        for v in prices:
            if v <= min_price:
                min_price = v
            elif v - min_price >= max_profit:
                max_profit = v - min_price
        return max_profit