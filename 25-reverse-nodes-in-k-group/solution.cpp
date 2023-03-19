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
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if (!head || k == 1) return head;
//         auto dummy = new ListNode(-1), pre = dummy;
//         dummy->next = head;
//         for (int i = 1; head; i++) {
//             if (i % k == 0) {
//                 pre = reverseOneGroup(pre, head->next);
//                 head = pre->next;
//             } else {
//                 head = head->next;
//             }
//         }
//         return dummy->next;
//     }
    
//     ListNode* reverseOneGroup(ListNode* prev, ListNode* next) {
//         auto left = prev->next, right = left->next;
//         while (right != next) {
//             left->next = right->next;
//             right->next = prev->next;
//             prev->next = right;
//             right = left->next;
//         }
//         return left;
//     }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; i ++) {
            if (!curr) return head;
            curr = curr->next;
        }
        ListNode* newHead = reverse(head, curr);
        head->next = reverseKGroup(curr, k);
        return newHead;
    }
    
    ListNode* reverse(ListNode* head, ListNode* tail_next) {
        ListNode * prev = nullptr, * curr = head, * next = head;
        while (curr != tail_next) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
