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
    int getMinimumDifference(TreeNode* root) {
        prev = nullptr;
        dfs(root);
        return res;
    }

private:
    TreeNode * prev;
    int res = INT_MAX;
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        if (prev) res = min(res, abs(root->val - prev->val));
        prev = root;
        dfs(root->right);
    }
};