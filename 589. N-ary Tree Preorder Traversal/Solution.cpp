/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        visit(result, root);
        return result;
        
    }
    
    void visit(vector<int> & res, Node * node) {
        if (node) {
            res.push_back(node->val);
            for (auto & ch : node->children) visit(res, ch);
        }
    }
};

