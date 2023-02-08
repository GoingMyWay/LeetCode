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
    int res = 0;
    int findTilt(TreeNode* root) {
        postOrderVisit(root);
        return res;
    }

    int postOrderVisit(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = postOrderVisit(root->left);
        int right = postOrderVisit(root->right);
        res += abs(left - right);
        return left + right + root->val;
    }
};