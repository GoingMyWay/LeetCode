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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // find the left and right
        ListNode * dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode * left = list1, * right = new ListNode(-1);
        for (int i = 1; i <= a - 1; i ++) {
            left = left->next;
        }
        
        right = left->next;
        for (int i = a; i <= b; i ++) {
            right = right->next;
        }
        
        left->next = list2;
        
        ListNode * curr = list2;
        while (curr->next) {
            curr = curr->next;
        }
        
        curr->next = right;
        return dummy->next;
    }
};