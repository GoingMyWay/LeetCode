class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        sum_v = sum(nums) if len(nums) != 0 else 0

        if sum_v < abs(target) or (sum_v + target) % 2 == 1:
            return 0
        
        return self.subsets(nums, (sum_v + target) // 2)
    
    def subsets(self, nums, sum_v):
        n = len(nums)
        dp = [[0] * (sum_v + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(1, n+1):
            for j in range(sum_v+1):
                if j >= nums[i-1]:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[n][sum_v]
