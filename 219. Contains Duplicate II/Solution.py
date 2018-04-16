class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        m_map = {}
        for i in xrange(len(nums)):
            if nums[i] in m_map and abs(m_map[nums[i]] - i) <= k:
                return True
            m_map[nums[i]] = i
        
        return False
            