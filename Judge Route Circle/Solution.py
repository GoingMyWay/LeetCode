class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        pos = [0, 0]
        for m in moves:
            if m == 'U':
                pos[1] += 1
            elif m == 'D':
                pos[1] -= 1
            elif m == 'L':
                pos[0] -= 1
            elif m == 'R':
                pos[0] += 1
        if pos[0] == 0 and pos[1] == 0:
            return True
        return False
