class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        sorted_envelopes = sorted(envelopes, key=lambda v: (v[0], -v[1]))
        heights = [v[1] for v in sorted_envelopes]
        return self.lengthOfLIS(heights)
    
    def lengthOfLIS(self, nums: List[int]) -> int:
        top = [0] * len(nums)
        piles = 0
        for i, poker in enumerate(nums):
            left, right = 0, piles
            while (left < right):
                mid = (left + right) // 2
                if (top[mid] < poker):
                    left = mid + 1
                elif (top[mid] > poker):
                    right = mid
                else:
                    right = mid
            if left == piles: piles += 1
            top[left] = poker
        return piles
