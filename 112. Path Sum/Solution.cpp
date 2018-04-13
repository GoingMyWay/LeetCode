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
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root ) return 0;
        if ( root->val == sum && root->left == NULL && root->right == NULL ) return 1;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

// BFS + queue
class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root ) return 0;
        queue<tuple<TreeNode*, int>> q;
        q.push(make_tuple(root, sum-root->val));
        while ( !q.empty() ) {
            tuple<TreeNode*, int> tp = q.front(); q.pop();
            TreeNode * p = get<0>(tp);
            int val = get<1>(tp);
            if ( !(p->left) && !(p->right) && val == 0 ) return 1;
            if ( p->left ) q.push(make_tuple(p->left, val-p->left->val));
            if ( p->right ) q.push(make_tuple(p->right, val-p->right->val));
        }
        return 0;
    }
};


// DFS + stack
class Solution3 {
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

