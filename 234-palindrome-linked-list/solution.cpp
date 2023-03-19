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

        // Return true if all elements in the list are equal to their corresponding elements in the reversed list
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;   // Define two pointers
        while (cur != nullptr) {   // Loop until the last node of the list is reached
            ListNode *next = cur->next;    // Store the next pointer temporarily
            cur->next = pre;               // Reverse the pointer
            pre = cur;                     // Move the pre pointer one step
            cur = next;                    // Move the cur pointer one step forward
        }
        return pre;            // Return the new head
    }
};
