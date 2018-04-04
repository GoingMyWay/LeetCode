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
    int answer = 0;
    int maxDepth(TreeNode* root) {
        visitTree(root, 1);
        // return answer;
        return visitTree(root);
    }

    // Top-Down recursion
    void visitTree(TreeNode * root, int depth) {
        if ( !root ) return;
        if ( !root->left && !root->right ) answer = max(answer, depth);
        else {
            visitTree(root->left, depth + 1);
            visitTree(root->right, depth + 1);
        }
    }

    // Bottom-Up Recursion
    int visitTree(TreeNode * root) {
        if ( !root ) return 0;
        int left_depth = visitTree(root->left);
        int right_depth = visitTree(root->right);
        return max(left_depth, right_depth) + 1;
    }

    // Bredth-Frist traversal
    int bredthFirst( TreeNode * root ) {
        queue<TreeNode *> q;
        q.push(root);
        int result = 0;
        
        while ( !q.empty() && root != NULL ) {
            result ++;
            int qsize = q.size();
            for ( int i = 0; i < qsize; i ++ ) {
                root = q.front(); q.pop();
                if ( root->left ) q.push(root->left);
                if ( root->right ) q.push(root->right);
            }
        }
        return result;
    }
};

