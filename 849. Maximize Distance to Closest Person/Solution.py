class Solution(object):
    def maxDistToClosest(self, seats):
        """
        :type seats: List[int]
        :rtype: int
        """
        l, r, res, temp = 0, 0, 1, 0
        for i, v in enumerate(seats):
            if v == 0:
                r += 1
            elif v == 1:
                r = i
                if seats[l] == 0:
                    res = r - l
                else:
                    if (r-l-1) % 2 == 0:
                        temp = (r-l-1) / 2
                    else:
                        temp = (r-l) / 2
                    if temp > res:
                        res = temp
                l, r = i, i

        return res if res > r-l else r-l

