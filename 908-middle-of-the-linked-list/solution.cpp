/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode * curr = head;
        while (curr) {
            count ++;
            curr = curr->next;
        }
        
        ListNode n = ListNode(-1); n.next = head;
        int i = 0;
        curr = &n;
        while (i < count/2+1) {
            i ++;
            curr = curr->next;
        }
        return curr;
    }
};
