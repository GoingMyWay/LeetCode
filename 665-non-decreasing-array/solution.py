class Solution(object):
    def checkPossibility(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        change_count = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if i-1 >= 1:
                    if nums[i] >= nums[i-2]:
                        nums[i-1] = nums[i]
                    else:
                        nums[i] = nums[i-1]
                    change_count += 1
                else:
                    nums[i-1] = nums[i]
                    change_count += 1
                    
                if change_count >= 2:
                    return False

        return True
