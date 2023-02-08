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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode * p = root;

        while ( !s.empty() || p ) {
            if ( p ) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode * n = s.top();
                if ( n->right == NULL ) {
                    result.push_back(n->val); s.pop();
                    if ( !s.empty() ) p = s.top();
                    else p = NULL;
                    
                    while ( p != NULL && p->right == n ) {
                        result.push_back(p->val); s.pop();
                        n = p;
                        
                        if ( !s.empty() ) p = s.top();
                        else p = NULL;
                    }
                    if ( p != NULL) p = p->right;
                } else p = n->right;
            }
        }
        return result;
    }
};