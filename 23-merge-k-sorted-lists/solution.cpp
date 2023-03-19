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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode * dummy = new ListNode(-1);
        ListNode * p = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto head: lists) {
            if (head) pq.push(head);
        }
        
        while (pq.size() > 0) {
            auto node = pq.top(); pq.pop();
            p->next = node;
            if (node->next) {
                pq.push(node->next);
            }
            p = node; // or p = p->next;
        }
        return dummy->next;
    }

private:
    // 自定义比较函数
    struct compare {
        bool operator() (ListNode * a, ListNode * b) {
            return a->val > b->val;
        }
    };
};
