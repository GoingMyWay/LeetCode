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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vs;
        vector<int> vals;
        inorder(root, vs, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vs.size(); i++) vs[i]->val = vals[i];
    }
    
    void inorder(TreeNode* root, vector<TreeNode*> & vs, vector<int> & vals) {
        if (root->left) inorder(root->left, vs, vals);
        vs.push_back(root);
        vals.push_back(root->val);
        if (root->right) inorder(root->right, vs, vals);
    }
};