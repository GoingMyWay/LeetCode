class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        counter = collections.Counter(filter(lambda v: v not in "!?',;.", paragraph.lower()).split())
        banned = set(banned)
        return sorted({k: v for k, v in counter.items() if k not in banned}.items(), key=lambda v: v[1], reverse=True)[0][0]
    
