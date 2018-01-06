/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        ListNode q = head;
        while(q!=null) {
            if(q.val == val) {
                p.next = q.next;
            } else {
                p = p.next;
            }
            q = q.next;
        }
        
        return dummy.next;
    }
}