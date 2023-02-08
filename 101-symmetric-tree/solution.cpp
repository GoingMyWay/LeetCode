/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
    
    bool isMirror(TreeNode * left, TreeNode * right) {
        if ( !left && !right ) return true;
        if ( !left || !right ) return false;
        return ( left->val == right->val ) 
            && isMirror(left->left, right->right) 
            && isMirror(left->right, right->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root); q.push(root);
        while ( !q.empty() ) {
            TreeNode * left = q.front(); q.pop();
            TreeNode * right = q.front(); q.pop();
            if ( !left && !right ) continue;
            if ( (!left || !right) || (left->val != right->val) ) return false;
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};