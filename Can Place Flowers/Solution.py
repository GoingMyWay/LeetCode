class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        count, i = 0, 0
        if len(flowerbed) == 1:
            count = 1 if flowerbed[i] == 0 else 0
            if count >= n:
                return True
            return False
            
        while i <= len(flowerbed) - 1:
            if i == 0 and flowerbed[i+1] == 0 and flowerbed[i] == 0:
                flowerbed[i], count = 1, count + 1
            elif i < len(flowerbed) - 1 and flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                flowerbed[i], count = 1, count + 1
            elif i == len(flowerbed) - 1 and flowerbed[i-1] == 0 and flowerbed[i] == 0:
                flowerbed[i], count = 1, count + 1
            i += 1
        if count >= n:
            return True
        return False
                