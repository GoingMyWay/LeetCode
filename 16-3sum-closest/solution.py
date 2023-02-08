class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = 0
        nums.sort()
        min_gap = sys.maxint
        
        for i in range(len(nums)-2):
            begin, end = i + 1, len(nums) - 1
            
            while begin < end:
                sum_v = nums[i] + nums[begin] + nums[end]
                
                gap = abs(sum_v - target)
                if gap < min_gap:
                    result = sum_v
                    min_gap = gap
                
                if sum_v > target:
                    end -= 1
                elif sum_v < target:
                    begin += 1
                else:
                    return sum_v

        return result
