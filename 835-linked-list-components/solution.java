/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        HashSet<Integer> set = new HashSet<>();
        for (int v : G) set.add(v);
        int result = 0;
        ListNode p = head;
        boolean prev = false;
        while (p != null) {
            boolean isFound = set.contains(p.val);
            if (isFound && !prev) result++;
            p = p.next;
            prev = isFound;
        }
        return result;
    }
}
