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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* node = findNthNodeFromEnd(dummy, n + 1);
        ListNode* p = node->next;
        node->next = node->next->next;
        delete p;
        return dummy->next;
    }
private:
    ListNode* findNthNodeFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        for (int i = 0; i < n; i ++) {
            p1 = p1->next;
            if (!p1) break;
        }
        ListNode * p2 = head;
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
