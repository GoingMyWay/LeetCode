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
    ListNode* swapNodes(ListNode* head, int k) {
        // Find the length of the linked list
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        
        // Find the kth node from the beginning of the linked list
        ListNode* firstPrev = nullptr;
        ListNode* first = head;
        for (int i = 0; i < k-1; i++) {
            firstPrev = first;
            first = first->next;
        }
        
        // Find the kth node from the end of the linked list
        ListNode* secondPrev = nullptr;
        ListNode* second = head;
        for (int i = 0; i < n-k; i++) {
            secondPrev = second;
            second = second->next;
        };

        // Swap nodes
        if (firstPrev) {
            firstPrev->next = second;
        } else {
            head = second;
        }
            
        if (secondPrev) {
            secondPrev->next = first;
        } else {
            head = first;
        }
            
        ListNode* temp = first->next;
        first->next = second->next;
        second->next = temp;
        return head;
    }
};