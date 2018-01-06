class Solution(object):
    def maximumProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min1, min2 = sys.maxint, sys.maxint
        max1, max2, max3 = -sys.maxint, -sys.maxint, -sys.maxint
        for v in nums:
            if v <= min1:
                min2, min1 = min1, v
            elif v < min2:
                min2 = v
            
            if v >= max3:
                max1, max2, max3 = max2, max3, v
            elif v > max1 and v <= max2:
                max1 = v
            elif v > max2:
                max1, max2 = max2, v
        
        a = max1 * max2 * max3
        b = min1 * min2 * max3
        if a >= b:
            return a
        else:
            return b
        