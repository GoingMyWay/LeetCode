class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        result = []
        m1_dict, m2_dict = {}, {}
        for v1 in nums1:
            if v1 in m1_dict:
                m1_dict[v1] += 1
            else:
                m1_dict[v1] = 1
        
        for v2 in nums2:
            if v2 in m2_dict:
                m2_dict[v2] += 1
            else:
                m2_dict[v2] = 1
        
        for k1, v1 in m1_dict.items():
            if k1 in m2_dict:
                if v1 >= m2_dict[k1]:
                    result.extend([k1] * m2_dict[k1])
                else:
                    result.extend([k1] * v1)
        
        return result
