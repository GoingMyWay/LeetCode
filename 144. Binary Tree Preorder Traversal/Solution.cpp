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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if ( root != NULL ) {
            result.push_back(root->val);
            vector<int> vec_left = this->preorderTraversal(root->left);
            vector<int> vec_right = this->preorderTraversal(root->right);
            result.insert(result.end(), vec_left.begin(), vec_left.end());
            result.insert(result.end(), vec_right.begin(), vec_right.end());
        }
        return result;
    }
    
};


class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; s.push(root);
        vector<int> result;
        
        while (!s.empty() && root) {
            TreeNode * node = s.top(); s.pop();
            result.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return result;
    }
};


