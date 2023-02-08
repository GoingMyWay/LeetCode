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
    ListNode* partition(ListNode* head, int x) {
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * prev = dummy, * curr = head;
        while (prev->next && prev->next->val < x) prev = prev->next;
        curr = prev;
        while (curr->next) {
            if (curr->next->val < x) {
                ListNode * temp = curr->next;
                curr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                prev = temp;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }   
};
