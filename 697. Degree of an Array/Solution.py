class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m_map = {}
        for v in nums:
            if v not in m_map:
                m_map[v] = 1
            else:
                m_map[v] += 1
        degree = max(m_map.values())
        degree_num = set()
        for k, v in m_map.items():
            if v == degree:
                degree_num.add(k)
        
        degree_index_forward = {}
        for index, val in enumerate(nums):
            if val in degree_num and val not in degree_index_forward:
                degree_index_forward[val] = index
        
        degree_index_back = {}
        index = len(nums) -1
        while index >= 0:
            val = nums[index]
            if val in degree_num and val not in degree_index_back:
                degree_index_back[val] = index
            index -= 1
        
        dists = []
        for k, v in degree_index_back.items():
            dists.append(v-degree_index_forward[k]+1)
            
        return min(dists) 
