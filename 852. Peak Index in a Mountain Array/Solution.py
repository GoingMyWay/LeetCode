class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        for i in range(len(A)-2):
            if A[i+1] - A[i] > 0 and A[i+1] - A[i+2] > 0:
                return i+1
        
