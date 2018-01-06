class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        stack = []
        for v in ops:
            if v != 'C' and v != 'D' and v != '+':
                stack.append(int(v))
            if v == 'C':
                stack.pop()
            if v == 'D':
                stack.append(stack[-1] * 2)
            if v == '+':
                stack.append(sum(stack[-2:]))
            
        return sum(stack)
