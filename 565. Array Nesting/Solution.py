class Solution(object):
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_v = 0
        
        for i in range(len(nums)):
            start, count = nums[i], 1
            if nums[i] != sys.maxint:
                while nums[start] != nums[i]:
                    count += 1
                    temp = start
                    start = nums[start]
                    nums[temp] = sys.maxint
                if count > max_v:
                    max_v = count
        return max_v
