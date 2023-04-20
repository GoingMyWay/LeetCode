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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> qnodes;
        queue<unsigned int> qnodeIds;
        qnodes.push(root);
        qnodeIds.push(1);
        int res = 1;
        while (qnodes.size() > 0) {
            int size = qnodes.size();
            vector<unsigned int> ids;
            for (int i = 0; i < size; i ++) {
                TreeNode * node = qnodes.front(); qnodes.pop();
                unsigned int nID = qnodeIds.front(); qnodeIds.pop();
                if (node->left) {
                    qnodes.push(node->left);
                    qnodeIds.push(nID * 2);
                }
                if (node->right) {
                    qnodes.push(node->right);
                    qnodeIds.push(nID * 2 + 1);
                }
                ids.push_back(nID);
            }
            res = max((unsigned int)res, ids[ids.size()-1]-ids[0]+1);
        }
        return res;
    }
};
