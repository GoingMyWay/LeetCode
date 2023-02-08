class Solution(object):
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        count_line, count = 1, 0
        for s in S:
            w = widths[ord(s)-ord('a')] 
            if count + w <= 100:
                count += w
            else:
                count_line += 1
                count = widths[ord(s)-ord('a')]
        return [count_line, count]
