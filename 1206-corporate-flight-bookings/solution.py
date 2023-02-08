class Difference(object):
    def __init__(self, nums: List[int]) -> None:
        self.diffs = [0] * len(nums)
        self.diffs[0] = nums[0]
        for i in range(1, len(nums)):
            self.diffs[i] = nums[i] - nums[i-1]
    
    def updates(self, i: int, j: int, inc: int) -> None:
        self.diffs[i] += inc
        if (j + 1 < len(self.diffs)):
            self.diffs[j + 1] -= inc

    def results(self):
        res = [0] * len(self.diffs)
        res[0] = self.diffs[0]
        for i in range(1, len(self.diffs)):
            res[i] = self.diffs[i] + res[i-1]
        return res


class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        nums = [0] * n
        difference = Difference(nums)
        for (i, j, inc) in bookings:
            difference.updates(i-1, j-1, inc)
        return difference.results()
