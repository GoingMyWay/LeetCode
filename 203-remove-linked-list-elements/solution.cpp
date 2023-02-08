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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        ListNode dummy(0);
        (&dummy)->next = head;
        ListNode* p = &dummy;
        ListNode* q = head;
        while (q)
        {
            if (q->val == val)
                p->next = q->next;
            else
            {
                p = p->next;
            }
            q = q->next;
        }
        
        return (&dummy)->next;
    }
};