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
    void connect(TreeLinkNode *root) {
        if ( !root ) return;
        TreeLinkNode * prev = root;
        TreeLinkNode * curr = NULL;
        TreeLinkNode * currLevelNext = NULL;
        while ( this->hasNextLevel(prev) ) {
            curr = prev;
            currLevelNext = NULL;
            while ( curr ) {
                // process current subtree
                if ( curr->left && !curr->right ) currLevelNext = curr->left;
                else if ( curr->left && curr->right ) {
                    curr->left->next = curr->right;
                    currLevelNext = curr->right;
                } else if ( !curr->left && curr->right ) {
                    currLevelNext = curr->right;
                }
                
                // process next subtree
                if ( curr->next ) {
                    if ( curr->next->left ) {
                        if ( !currLevelNext ) currLevelNext = curr->next->left;
                        else currLevelNext->next = curr->next->left;
                    } else if ( curr->next->right ) {
                        if ( !currLevelNext ) currLevelNext = curr->next->right;
                        else currLevelNext->next = curr->next->right;
                    }
                }
                curr = curr->next; // get the next current node of the current level
            }
            // get the next left-most node of the next level
            prev = this->getNextLevelFirstNode(prev);
        }
    }
    
    bool hasNextLevel(TreeLinkNode *root) {
        while ( root ) {
            if ( root->left || root->right ) return 1;
            root = root->next;
        }
        return 0;
    }
    
    TreeLinkNode * getNextLevelFirstNode(TreeLinkNode * root) {
        while ( root ) {
            if ( root->left ) return root->left;
            else if ( root->right ) return root->right;
            root = root->next;
        }
        return NULL;
    }
};


