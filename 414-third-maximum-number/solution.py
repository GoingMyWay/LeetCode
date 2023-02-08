class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return max(nums)
        
        m_map = {}
        for v in nums:
            m_map[v] = m_map.get(v, 0) + 1
        if len(m_map.keys()) < 3:
            return max(nums)
        
        max_v, sec_v, third_v = -sys.maxint, -sys.maxint, -sys.maxint
        for v in nums:
            if v > max_v:
                third_v = sec_v
                sec_v = max_v
                max_v = v
            elif v > sec_v and v != max_v:
                third_v = sec_v
                sec_v = v
            elif v > third_v and v != sec_v and v != max_v:
                third_v = v

        return third_v
        