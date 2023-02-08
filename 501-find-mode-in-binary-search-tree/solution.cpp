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
    vector<int> result;
    int maxFreq = 0, current = 0, freq = 0;
    
    vector<int> findMode(TreeNode* root) {
        // base condition
        if (!root) return result;

        // traverse left sub tree    
        findMode(root->left);
        
        // upon visiting a node
        if (current != root->val) {
           freq = 1;
           current = root->val;
        } else if (current == root->val) {
            freq ++;   
        }
        
        if (freq > maxFreq) {
            maxFreq = freq;
            result = {current};
        } else if (freq == maxFreq) {
            result.push_back(current);
        }
        // traverse right subtree
        findMode(root->right);   
        return result;
    }
};
