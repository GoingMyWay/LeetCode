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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if ( root == NULL ) return result;
        
        queue<TreeNode*> q; q.push(root);
        
        while ( !q.empty() ) {
            int qsize = q.size();
            double avg = 0;
            for ( int i = 0; i < qsize;  ++ i ) {
                TreeNode * n = q.front(); q.pop();
                avg += n->val;
                if ( n->left ) q.push(n->left);
                if ( n->right ) q.push(n->right);
            }
            result.push_back(avg/qsize);
        }
        return result;
    }
};
