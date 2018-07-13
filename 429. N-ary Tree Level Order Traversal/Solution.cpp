/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q; q.push(root);
        while (!q.empty() && root) {
            vector<int> res;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                Node* n = q.front(); q.pop();
                res.push_back(n->val);
                for (auto & ch : n->children) q.push(ch);
            }
            result.push_back(res);
        }
        return result;
    }
};

