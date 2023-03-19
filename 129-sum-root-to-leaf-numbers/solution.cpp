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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size() > 0) {
            auto node = st.top(); st.pop();
            if (!node->left && !node->right) {
                res += node->val;
            }

            if (node->left) {
                node->left->val += node->val * 10;
                st.push(node->left); 
            }
            if (node->right) {
                node->right->val += node->val * 10;
                st.push(node->right); 
            }
        }
        return res;
    }
};
