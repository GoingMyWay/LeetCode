class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        ans = None
        sums = 0
        for x in xrange(len(nums)):
            sums += nums[x]
            if x >= k: sums -= nums[x - k]
            if x >= k - 1: ans = ans if (ans > 1.0 * sums / k) else (1.0 * sums / k)
        return ans
