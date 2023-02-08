class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        left, right = max(weights), sum(weights)

        while left <= right:
            mid = left + (right - left) // 2
            if (self.f(weights, mid) > days):
                left = mid + 1
            elif (self.f(weights, mid) < days):
                right = mid - 1
            elif (self.f(weights, mid) == days):
                right = mid - 1
        return left
    
    def f(self, weights, x):
        days = 0
        i = 0
        while (i < len(weights)):
            cap = x
            while (i < len(weights)):
                if cap < weights[i]:
                    break
                else:
                    cap -= weights[i]
                i += 1
            days += 1
        return days
