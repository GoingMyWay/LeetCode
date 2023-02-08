class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        for i in range(n+1):
            res.append(sum([int(_v) for _v in "{0:b}".format(i)]))
        return res
