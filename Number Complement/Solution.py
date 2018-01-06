class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num == 0:
            return 1
        i = 1
        while i <= num:
             i <<= 1
        return (i - 1) ^ num


# class Solution(object):
#     def findComplement(self, num):
#         """
#         :type num: int
#         :rtype: int
#         """
#         num_v = num
#         if num == 0:
#             return 1
        
#         count = 1
#         if num % 2 != 0:
#             num -= 1
            
#         while num > 0:
#             count += 1
#             num = num >> 1
#             if num % 2 != 0:
#                 num -= 1

#         return num_v ^ (2 ** count - 1)
