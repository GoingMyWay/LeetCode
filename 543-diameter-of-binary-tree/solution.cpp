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
    int maxDepth = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        postOrderVisit(root);
        return maxDepth;
    }

    int postOrderVisit(TreeNode * root) {
        if (root == nullptr) return 0;

        int leftDepth = postOrderVisit(root->left);
        int rightDepth = postOrderVisit(root->right);
        maxDepth = max(leftDepth + rightDepth, maxDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};