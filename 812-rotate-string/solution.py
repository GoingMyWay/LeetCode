class Solution(object):
    def rotateString(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        for step in range(len(A)):
            for idx in range(len(A)):
                if A[(idx+step) % len(A)] != B[idx]:
                    break
            else:
                return True
        return False
        