class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # if x < 0:
        #     v = int(str(x)[1:][::-1])
        #     if v > 2**31:
        #         return 0
        #     else:
        #         return -v
        # else:
        #     v = int(str(x)[::-1])
        #     if v > 2**31-1:
        #         return 0
        #     else:
        #         return v
        ans = 0
        is_neg = x < 0 
        if is_neg:
            x = -x
        while x:
            ans = ans * 10 + x % 10
            x //= 10
            if ans > 2**31-1 or ans < -2**31:
                return 0
            
        return -ans if is_neg else ans 