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
    int goodNodes(TreeNode* root) {
        if (!root) return res;
        dfs(root, root->val);
        return res;
    }

    void dfs(TreeNode* curr, int maxv) {
        if (curr->val >= maxv) {
            maxv = max(maxv, curr->val);
            res ++;
        }
        if (curr->left) {
            dfs(curr->left, maxv);
        }
        if (curr->right) {
            dfs(curr->right, maxv);
        }
    }

private:
    int maxv = 0, res = 0;
};