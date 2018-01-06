class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        change_time = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if i-1 >= 1 and nums[i] >= nums[i-2]:
                    nums[i-1] = nums[i]
                    change_time += 1
                elif i-1 >= 1 and nums[i] < nums[i-2]:
                    nums[i] = nums[i-1]
                    change_time += 1
                elif nums[i] < nums[i-1]:
                    nums[i-1] = nums[i]
                    change_time += 1
                if change_time >= 2:
                    return False

        return True 
