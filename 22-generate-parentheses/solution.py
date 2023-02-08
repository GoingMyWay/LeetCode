class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        self.add_paran(result, '', n, left=n, right=n)
        return result

    def add_paran(self, result, s_str, n,  left, right):
        if left == 0 and right == 0:
            result.append(s_str)
            return

        if left > 0:
            self.add_paran(result, s_str + '(', n, left - 1, right)
        if n-left > n-right:
            self.add_paran(result, s_str + ')', n, left, right - 1)
