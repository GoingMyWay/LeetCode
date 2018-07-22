/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        traverse(root1, res1);
        traverse(root2, res2);
        if (res1.size() != res2.size()) return 0;
        for (int i = 0; i < res1.size(); i ++) {
            if (res1[i] != res2[i]) return 0;
        }
        return 1;
    }
    
    void traverse(TreeNode* root, vector<int> & vec) {
        if (!root->left && !root->right) vec.push_back(root->val);
        else {
            if (root->left) traverse(root->left, vec);
            if (root->right) traverse(root->right, vec);
        }
    }
};

