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

# class Solution(object):
#     def constructArray(self, n, k):
#         ans = list(range(1, n - k))
#         for i in range(k+1):
#             if i % 2 == 0:
#                 ans.append(n-k + i//2)
#             else:
#                 ans.append(n - i//2)

#         return ans

class Solution(object):
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        res = range(1, n+1)
        for i in range(2, k+1): res = res[:i-1] + res[i-1:][::-1]
        return res
    