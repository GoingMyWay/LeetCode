class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        stack, sum_v = [], 0
        for v in ops:
            if v != 'C' and v != 'D' and v != '+':
                stack.append(int(v))
                sum_v += stack[-1]
            elif v == 'C':
                sum_v -= stack[-1]
                stack.pop()
            elif v == 'D':
                stack.append(stack[-1] * 2)
                sum_v += stack[-1]
            elif v == '+':
                stack.append(sum(stack[-2:]))
                sum_v += stack[-1]
                
        return sum_v
