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
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int i = 0, res = 0;
        ListNode * p = head;
        while (p != nullptr) {
            i ++;
            if (0 == rd() % i) {
                res = p->val;
            }
            p = p->next;
        }
        return res;
    }

private:
    ListNode * head;
    random_device rd;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */