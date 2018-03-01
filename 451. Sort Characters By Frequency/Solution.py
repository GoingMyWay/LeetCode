class Solution(object): 
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        return ''.join(k*v for k, v in sorted(dict(collections.Counter(s)).items(), key=lambda v: v[1], reverse=True))

