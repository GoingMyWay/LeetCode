/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;
        while (head)
        {
            temp.push_back(head->val);
            head = head->next;
        }
        int len = temp.size();
        for (int i = 0; i < len/2 ; i++)
        {
            if (temp[i] != temp[len-i-1])
            {
                return 0;
            }
        }
        
        return 1;
    }
};