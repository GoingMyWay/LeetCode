/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS + stack
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root ) return 0;
        stack<tuple<TreeNode*, int>> s;
        s.push(make_tuple(root, sum-root->val));
        while ( !s.empty() ) {
            tuple<TreeNode*, int> tp = s.top(); s.pop();
            TreeNode * p = get<0>(tp);
            int val = get<1>(tp);
            if ( !(p->left) && !(p->right) && val == 0 ) return 1;
            if ( p->right ) s.push(make_tuple(p->right, val-p->right->val));
            if ( p->left ) s.push(make_tuple(p->left, val-p->left->val));
        }
        return 0;
    }
};

