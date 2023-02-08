class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
#         import collections
#         counter = collections.Counter(candies)
#         all_sum = 0
#         count = 0
#         for k, v in counter.iteritems():
#             all_sum += 1
#             count += 1
#             if all_sum == len(candies) / 2:
#                 return count
    
#         return len(counter)
        return min(len(candies)/2, len(set(candies)))
