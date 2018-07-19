class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s1, s2 = [], []
        for v1 in S:
            if v1 != '#':
                s1.append(v1)
            elif len(s1) != 0:
                s1.pop();
        
        for v2 in T:
            if v2 != '#':
                s2.append(v2)
            elif len(s2) != 0:
                s2.pop();

        return ''.join(s1) == ''.join(s2)

