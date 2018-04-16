class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        dim, all_data = 0, []
        for line in nums:
            dim += len(line)
            all_data.extend(line)
        
        if dim != r * c:
            return nums
        
        result = []
        for _r in range(r):
            result.append(all_data[_r*c:(_r+1)*c])
        return result
