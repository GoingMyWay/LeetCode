class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        dp = [0] * len(cost)
        dp[0], dp[1] = cost[0], cost[1]
        
        for idx in range(2, len(cost)):
            dp[idx] = cost[idx] + min(dp[idx-2], dp[idx-1])
        return min(dp[-1], dp[-2]) 
