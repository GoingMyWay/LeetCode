class Solution:
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        hash_map = {k: idx for idx, k in enumerate(list1)}
        best, result = 1e9, []
        for idx, k in enumerate(list2):
            if hash_map.get(k, 1e9) + idx < best:
                best = hash_map.get(k, 1e9) + idx
                result = [k]
            elif hash_map.get(k, 1e9) + idx == best:
                result.append(k)
        return result