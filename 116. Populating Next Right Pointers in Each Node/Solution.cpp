/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // Bredth-First Search Method + Queue
    void connect1(TreeLinkNode *root) {
        if ( !root ) return;
        queue<TreeLinkNode*> q; q.push(root);
        while ( !q.empty() ) {
            int qsize = q.size() - 1;
            TreeLinkNode * prev = q.front(); q.pop();
            if ( prev->left ) q.push(prev->left);
            if ( prev->right ) q.push(prev->right);
            for ( int i = 0; i < qsize; i ++ ) {
                TreeLinkNode * p = q.front(); q.pop();
                prev->next = p; prev = p;
                if ( p->left ) q.push(p->left);
                if ( p->right ) q.push(p->right);
            }
        }
    }
    
    // iterative method constant extra memory
    void connect(TreeLinkNode *root) {
        if ( !root ) return;
        TreeLinkNode * prev = root;
        TreeLinkNode * curr = NULL;
        while ( prev->left ) { // next level
            curr = prev;
            while ( curr ) {   // process the current level
                curr->left->next = curr->right;
                // procee the next subtree in the current level
                if ( curr->next ) curr->right->next = curr->next->left;
                curr = curr->next;  // point to the next subtree root
            }
            prev = prev->left;  // point to the left-most node of the next level
        } 
    }
};

