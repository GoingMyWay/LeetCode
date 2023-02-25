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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);
        // 为 true 时向右，false 时向左
        bool flag = true;

        // while 循环控制从上向下一层层遍历
        while (q.size() > 0) {
            int sz = q.size();
            // 记录这一层的节点值
            vector<int> level;;
            // for 循环控制每一层从左向右遍历
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front(); q.pop();;
                // 实现 z 字形遍历
                if (flag) level.push_back(cur->val);
                else level.insert(level.begin(), cur->val);
                
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            // 切换方向
            flag = !flag;
            res.push_back(level);
        }
        return res;
    }
};