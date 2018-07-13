/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST2(TreeNode* root, int val) {
        if (!root) return NULL;
        else if (root->val == val) return root;
        else if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }

    TreeNode* searchBST3(TreeNode* root, int val) {
        stack<TreeNode*> s; s.push(root);
        while (!s.empty() && root) {
            TreeNode* n = s.top(); s.pop();
            if (n == NULL) return NULL;
            else if (n->val == val) return n;
            else if (n->val > val) s.push(n->left);
            else s.push(n->right);
        }
        return NULL;
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while (node) {
            if (node->val == val) return node;
            else if (node->val > val) node = node->left;
            else node = node->right;
        }
        return NULL;
    }
};

