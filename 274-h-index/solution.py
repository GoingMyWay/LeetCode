class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if len(citations) == 0 or max(citations) == 0:
            return 0
        citations = sorted(citations, reverse=True)
        for idx, v in enumerate(citations):
            if v < idx + 1: return idx
        return idx + 1
