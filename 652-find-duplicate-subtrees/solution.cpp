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
    unordered_map<string, int> memo;
    vector<TreeNode*> res;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }

        string left = traverse(root->left);
        string right = traverse(root->right);

        string sub_tree = left + ',' + right + ',' + to_string(root->val);

        if (memo.find(sub_tree) == memo.end()) {
            memo[sub_tree] = 0;
        }

        int freq = memo[sub_tree];
        if (freq == 1) {
            res.push_back(root);
        }
        memo[sub_tree] += 1;

        return sub_tree;
    }
};
