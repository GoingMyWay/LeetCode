class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_map = {}
        for v in nums:
            hash_map[v] = hash_map.get(v, 0) + 1
        
        sort_list = sorted(hash_map.keys())
        max_len = 0
        for i in range(len(sort_list)-1):
            if abs(sort_list[i] - sort_list[i+1]) == 1:
                if hash_map[sort_list[i]] + hash_map[sort_list[i+1]] >= max_len:
                    max_len = hash_map[sort_list[i]] + hash_map[sort_list[i+1]]
        return max_len
