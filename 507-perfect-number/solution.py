class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0: return False
        ans, sqrt = 0, int(num**0.5)
        ans = sum(v+num//v for v in xrange(1, sqrt+1) if num%v==0)
        if sqrt ** 2 == num:
            ans -= sqrt
        return ans-num==num
