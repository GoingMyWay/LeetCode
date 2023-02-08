class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        self.memo = {}

        def dp(i):
            if i <= 1: return 0
            if i in self.memo: return self.memo[i]

            one_step = cost[i-1] + dp(i-1)
            two_step = cost[i-2] + dp(i-2)
            self.memo[i] = min(one_step, two_step)
            return self.memo[i]
        
        return dp(len(cost))
