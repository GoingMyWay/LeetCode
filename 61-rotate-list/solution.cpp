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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int n = 0;
        ListNode * curr = head, * fast = head, * slow = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        // fast pointer 
        k %= n;
        for (int i = 0; i < k; i ++) {
            if (fast) fast = fast->next;
        }
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        
        return fast;
    }
};