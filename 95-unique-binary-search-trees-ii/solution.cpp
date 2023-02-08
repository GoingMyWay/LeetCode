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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return build(1, n);
    }

    vector<TreeNode*> build(int low, int high) {
        vector<TreeNode*> res;
        if (low > high) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = low; i <= high; i ++) {
            vector<TreeNode*> leftNodes = build(low, i-1);
            vector<TreeNode*> rightNodes = build(i+1, high);
            for (TreeNode* leftNode: leftNodes) {
                for (TreeNode* rightNode: rightNodes) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

};