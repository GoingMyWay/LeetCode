# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        len_1, len_2 = 0, 0
        curr_1, curr_2 = l1, l2
        
        while curr_1 != None:
            len_1 += 1
            curr_1 = curr_1.next
        
        while curr_2 != None:
            len_2 += 1
            curr_2 = curr_2.next
        
        curr_1, curr_2 = l1, l2
        
        a, i = 0, 0
        while curr_1 != None:
            a += curr_1.val * 10 ** (len_1 - i - 1)
            curr_1 = curr_1.next
            i += 1
        
        b, j = 0, 0
        while curr_2 != None:
            b += curr_2.val * 10 ** (len_2 - j - 1)
            curr_2 = curr_2.next
            j += 1
        
        c = a + b
        
        dummy =  ListNode(sys.maxint)
        curr = dummy
        for i in str(c):
            node = ListNode(int(i))
            curr.next = node
            curr = node
        return dummy.next        
