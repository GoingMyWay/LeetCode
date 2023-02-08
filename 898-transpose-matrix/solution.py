class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        r, c = len(A[0]), len(A)
        result = [[0]*c for _ in range(r)]
        for i in range(len(A)):
            for j in range(len(A[0])):
                result[j][i] = A[i][j]
        return result