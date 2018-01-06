# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return head
        
        if head.next is None:
            return head
        
        val_odd, val_even = [], []
        curr_odd, curr_even =  head, head.next
        
        while curr_odd != None:
            val_odd.append(curr_odd.val)
            if curr_odd.next == None or curr_odd.next.next == None:
                break
            curr_odd = curr_odd.next.next
    
        while curr_even != None:
            val_even.append(curr_even.val)
            if curr_even.next == None or curr_even.next.next == None:
                break
            curr_even = curr_even.next.next
        
        curr = head
        for v in val_odd+val_even:
            curr.val = v
            curr = curr.next
        return head
