class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        sum_time = 0
        if len(timeSeries) == 0:
            return 0
        
        for i in xrange(len(timeSeries)-1):
            if timeSeries[i] + duration <= timeSeries[i+1]:
                sum_time += duration
            else:
                sum_time += timeSeries[i+1] - timeSeries[i]
        
        sum_time += duration
        
        return sum_time

# class Solution(object):
#     def findPoisonedDuration(self, timeSeries, duration):
#         ans = duration * len(timeSeries)
#         for i in xrange(1,len(timeSeries)):
#             ans -= max(0, duration - (timeSeries[i] - timeSeries[i-1]))
#         return ans