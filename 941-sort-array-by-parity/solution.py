class Solution:
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        res = []
        for v in A:
            if v % 2 == 0:
                res.append(v)
        for v in A:
            if v % 2 != 0:
                res.append(v)
        return res;