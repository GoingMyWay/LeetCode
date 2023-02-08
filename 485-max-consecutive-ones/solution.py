class Solution(object):
    # def findMaxConsecutiveOnes(self, nums):
    #     sum_v, v = 0, 0
    #     for i in xrange(len(nums)):
    #         v = (v + nums[i]) * nums[i]
    #         if v >= sum_v:
    #             sum_v = v
    #     return sum_v
    
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = []
        p1, p2, max_len = 0, 0, 0
        
        for i in xrange(len(nums)):
            if i == 0 and nums[i] == 1:
                # result.append([i])
                p1, p2 = i, i
                if p2 - p1 + 1 >= max_len:
                    max_len = p2 - p1 + 1
            if i > 0 and nums[i] == 1 and nums[i] == nums[i-1]:
                # result[-1].append(i)
                p2 = i
                if p2 - p1 + 1 >= max_len:
                    max_len = p2 - p1 + 1
            elif i > 0 and nums[i] == 1 and nums[i] != nums[i-1]:
                # result.append([i])
                p1, p2 = i, i
                if p2 - p1 + 1 >= max_len:
                    max_len = p2 - p1 + 1


                
        # if len(result) == 0:
            # return 0
        # return max([len(v) for v in result])

        return max_len
