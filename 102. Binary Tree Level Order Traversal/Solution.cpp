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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if ( root == NULL ) return result;
        queue<TreeNode*> q; q.push(root);
        
        while ( !q.empty() ) {
            vector<int> chd;
            int qsize = q.size();
            for ( int i = 0; i < qsize; ++ i ) {
                TreeNode * n = q.front();
                q.pop();
                chd.push_back(n->val);
                if ( n->left ) q.push(n->left);
                if ( n->right ) q.push(n->right);
            }
            result.push_back(chd);
        }
        return result;
    }
};

