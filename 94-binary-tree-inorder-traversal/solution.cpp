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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode * p = root;
        
        while ( !s.empty() || p ) {
            if ( p ) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode * n = s.top(); s.pop();
                result.push_back(n->val);
                p = n->right;
            }
        }
        return result;
    }
};