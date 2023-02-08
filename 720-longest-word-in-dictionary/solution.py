class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        m_set = set([''])
        for w in sorted(words):
            if w[:-1] in m_set:
                m_set.add(w)
        return min([w for w in m_set if len(w) == max(map(len, m_set))])
