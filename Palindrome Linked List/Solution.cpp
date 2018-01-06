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
        ListNode* ptr = head;
        while(ptr!=NULL)
        {
            temp.push_back(ptr->val);
            ptr = ptr->next;
        }
        int n = temp.size();
        for(int i = 0; i < n/2; i++)
        {
            if(temp[i] != temp[n-1-i])
                return false;
        }
        return true;
    }
};