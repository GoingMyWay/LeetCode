class Solution(object):
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        hash_map = {val: index for index, val in enumerate(B)}
        return [hash_map[val] for val in A]
    