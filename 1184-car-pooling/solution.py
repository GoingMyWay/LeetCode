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

    def results(self, capacity: int):
        res = [0] * len(self.diffs)
        res[0] = self.diffs[0]
        if res[0] > capacity: return False
        for i in range(1, len(self.diffs)):
            res[i] = self.diffs[i] + res[i-1]
            if res[i] > capacity:
                return False
        return True


class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        nums = [0] * 1001
        difference = Difference(nums)
        for (inc, i, j) in trips:
            difference.updates(i, j-1, inc)
        return difference.results(capacity)
