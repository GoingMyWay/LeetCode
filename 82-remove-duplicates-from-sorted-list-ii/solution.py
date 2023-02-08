# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(None)
        dummy.next, prev = head, dummy
        
        while (prev.next):
            curr = prev.next
            flag = False
            while (curr and curr.next and curr.val == curr.next.val):
                curr = curr.next
                flag = True
            
            if flag: prev.next = curr.next
            else: prev = prev.next
        return dummy.next
