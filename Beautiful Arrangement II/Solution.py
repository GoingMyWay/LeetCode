class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        result = range(1, n-k+1)
        i = k
        while i > 0:
            v_1, v_2 = result[-1] + i, result[-1] - i
            if v_2 <= 0:
                result.append(v_1)
            elif v_1 <= n:
                if v_1 in result:
                    result.append(v_2)
                else:
                    result.append(v_1)
            else:
                result.append(v_2)
            i -= 1
        
        return result
