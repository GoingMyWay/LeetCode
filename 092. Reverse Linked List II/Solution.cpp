/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        
        ListNode * dummy = new ListNode(-1), * prev = dummy;
        dummy->next = head;
        for (int i = 1; i <= left - 1; i ++) prev = prev->next;

        ListNode * l = prev->next, * r = prev->next->next;
        for (int i = left; i < right; i++) {
            ListNode * temp = r->next;
            r->next = l;
            l = r;
            r = temp;
        }
        prev->next->next = r;
        prev->next = l;
        return dummy->next;
    }
};
