class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        hash_map = {v+1: 0 for v in range(len(nums))}
        for v in nums:
            hash_map[v] += 1
        
        res = [-1, -1]
        for k, v in hash_map.items():
            if v == 2:
                res[0] = k
            elif v == 0:
                res[1] = k
        
        return res