# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        
        ret_head = head.next
        curr_1, curr_2 = head, head.next
        pre = None
        
        while curr_1 != None and curr_2 != None:
            curr_1.next = curr_2.next
            curr_2.next = curr_1
            curr_1, curr_2 = curr_2, curr_1
            if pre != None:
                pre.next = curr_1
                
            if curr_1.next == None or curr_2.next == None:
                return ret_head
            pre = curr_2
            curr_1 = curr_1.next.next
            curr_2 = curr_2.next.next
        
        return ret_head
