class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1] * len(nums)  # basecase

        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], 1 + dp[j])
        return max(dp)

        # top = [0] * len(nums)
        # piles = 0
        # for i, poker in enumerate(nums):
        #     left, right = 0, piles
        #     while (left < right):
        #         mid = (left + right) // 2
        #         if (top[mid] < poker):
        #             left = mid + 1
        #         elif (top[mid] > poker):
        #             right = mid
        #         else:
        #             right = mid
        #     if left == piles: piles += 1
        #     top[left] = poker
        # return piles
