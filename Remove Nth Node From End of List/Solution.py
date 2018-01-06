# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        curr, p = head, head
        
        count = 0
        while curr != None:
            count += 1
            curr = curr.next
        
        i = 1
        pre = None
        while p != None:
            if i == count - n + 1:
                if pre != None:
                    pre.next = p.next
                else:
                    head = head.next
                return head
            i += 1
            pre = p
            p = p.next
    
        return head