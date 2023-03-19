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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        
        vector<int> vals;
        ListNode* curr = head;
        while (curr) {
            vals.push_back(curr->val);
            curr = curr->next;
        }
        return BST(vals, 0, vals.size()-1);
    }

private:
    TreeNode* BST(vector<int>& vals, int left, int right) {
        if (left > right) return nullptr;

        int i = left + (right - left) / 2;
        TreeNode* node = new TreeNode(vals[i]);
        if (left == right) return node;
        
        node->left = BST(vals, left, i - 1);
        node->right = BST(vals, i + 1, right);
        return node;
    }
};