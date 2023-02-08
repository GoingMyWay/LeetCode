/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) {
            q.push(root);
        }
        Node* curr;
        while (!q.empty()) {
            int size = q.size();
            if (size > 0) {
                curr = q.front(); q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                for (int i = 0; i < size-1; i ++) {		// traverse nodes in the same level
                    Node * node = q.front(); q.pop();
                    curr->next = node;
                    curr = node;
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
        }
        return root;
    }
};