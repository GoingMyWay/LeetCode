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
// class Solution {
// public:
//     int longestZigZag(TreeNode* root) {
//         return dfs(root)[2];
//     }

// private:
//     vector<int> dfs(TreeNode* root) {
//         if (!root) return {-1, -1, -1};
//         vector<int> left = dfs(root->left);
//         vector<int> right = dfs(root->right);
//         int res = max(max(left[1], right[0]) + 1,
//                       max(left[2], right[2]));
//         return {left[1] + 1, right[0] + 1, res};
//     }
// };

class Solution {
public:
    int maxStep = 0;
    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxStep;
    }
    
    void dfs(TreeNode* root, bool isLeft, int step) {
        if (!root) return;
        maxStep = max(maxStep, step); // update max step sofar
        if (isLeft) {
            dfs(root->left, false, step + 1); // keep going from root to left
            dfs(root->right, true, 1); // restart going from root to right
        } else {
            dfs(root->right, true, step + 1); // keep going from root to right
            dfs(root->left, false, 1); // restart going from root to left
        }
    }
};
