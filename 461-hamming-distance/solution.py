class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z, count = x ^ y, 0
        
        if z == 0:
            return 0
        elif z % 2 == 0:
            return self.cal(z, count)
        else:
            count += 1
            return self.cal(z, count)
    
    def cal(self, z, count):
        while z > 0:
            z >>= 1
            if z % 2 != 0:
                count, z = count + 1, z - 1
        return count
# class Solution(object):
#     def hammingDistance(self, x, y):
#         """
#         :type x: int
#         :type y: int
#         :rtype: int
#         """
#         x = x ^ y
#         y = 0
#         while x:
#             y += 1
#             x = x & (x - 1)
#         return y