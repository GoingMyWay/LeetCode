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

// public:
//     bool isPalindrome(ListNode* head) {
//         left = head;
//         return traverse(head);
//     }

// private:
//     ListNode * left;
//     bool traverse(ListNode* right) {
//         if (right == nullptr) return true;
//         bool res = traverse(right->next);
//         res = res && (left->val == right->val);
//         left = left->next;
//         return res;
//     }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;   // Define two pointers
        slow = fast = head;      // Initialize the pointers
        // Loop until fast pointer reaches the end
        while (fast != nullptr && fast->next != nullptr) { 
            slow = slow->next;   // Move slow pointer one step
            fast = fast->next->next;   // Move fast pointer two step
        }

        if (fast != nullptr)    // If fast pointer is not nullptr
            slow = slow->next;  // Move the slow pointer one step

        ListNode *left = head;  // Initialize left pointer to head
        // Reverse the right half of the list and make the right pointer point to the new head
        ListNode *right = reverse(slow);
        while (right != nullptr) {        // Loop until right pointer is nullptr
            if (left->val != right->val)  // If the values of left and right pointers are not equal
                return false;            // Return false
            left = left->next;           // Move the left pointer one step
            right = right->next;         // Move the right pointer one step
        }

        return true;
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode * pre = nullptr;
        ListNode * cur = head;
        while (cur != nullptr) {
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
