class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        self.add_paran(result, '', left=n, right=0)
        return result

    def add_paran(self, result, s_str, left, right):
        if left == 0 and right == 0:
            result.append(s_str)
            return

        if right > 0:
            self.add_paran(result, s_str + ')', left, right - 1)
        if left > 0:
            self.add_paran(result, s_str + '(', left - 1, right + 1)

