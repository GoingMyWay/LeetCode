class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = [0] * len(nums)
        dp[0] = nums[0]
        decrease = collections.deque()
        for i in range(len(nums)):
            while len(decrease) > 0 and decrease[0] < i - k:
                decrease.popleft()
            dp[i] = nums[i]
            if len(decrease) > 0:
                dp[i] = max(nums[i], dp[decrease[0]] + nums[i])
            while decrease and dp[decrease[-1]] <= dp[i]:
                decrease.pop()
            decrease += [i]
        return max(dp)
