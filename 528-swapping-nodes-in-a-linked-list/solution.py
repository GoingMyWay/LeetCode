# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # Find the length of the linked list
        n = 0
        curr = head
        while curr:
            n += 1
            curr = curr.next
        
        # Find the kth node from the beginning of the linked list
        first_prev = None
        first = head
        for i in range(k-1):
            first_prev = first
            first = first.next
        
        # Find the kth node from the end of the linked list
        second_prev = None
        second = head
        for i in range(n-k):
            second_prev = second
            second = second.next
        
        # Swap the nodes
        if first_prev:
            first_prev.next = second
        else:
            head = second
            
        if second_prev:
            second_prev.next = first
        else:
            head = first
            
        first.next, second.next = second.next, first.next
        
        return head
