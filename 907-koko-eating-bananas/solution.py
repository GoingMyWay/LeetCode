class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def f(piles, speed):
            hours = 0
            for x in piles:
                hours += x // speed
                if x % speed > 0:
                    hours += 1
            return hours
        
        left, right = 1, 10**9

        # left bound binary search
        while (left <= right):
            mid = left + (right - left) // 2
            if (f(piles, mid) > h):
                left = mid + 1
            elif (f(piles, mid) < h):
                right = mid - 1
            elif (f(piles, mid) == h):
                right = mid - 1
        return left
