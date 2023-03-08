/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // int maxDepth(Node* root) {
    //     if (!root) return 0;
    //     queue<Node*> q;
    //     q.push(root);
    //     int res = 0;
    //     while (q.size() > 0) {
    //         int size = q.size();
    //         for (int i = 0; i < size; i ++) {
    //             auto node = q.front(); q.pop();
    //             for (auto c : node->children) {
    //                 if (c) q.push(c);
    //             }
    //         }
    //         res ++;
    //     }
    //     return res;
    // }
    int maxDepth(Node* root) {
        if (!root) return 0;
        int max_depth = INT_MIN;
        for (auto c : root->children) {
            max_depth = max(max_depth, maxDepth(c));
        }
        return (max_depth == INT_MIN ? 0 : max_depth) + 1;
    }
};
