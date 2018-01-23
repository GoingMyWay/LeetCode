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
            if (idx+1 == v) or (idx < len(citations) - 1 and v > idx+1 and idx+2 > citations[idx+1]):
                return idx + 1
        return idx + 1

