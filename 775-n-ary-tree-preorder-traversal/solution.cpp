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
    vector<int> preorder2(Node* root) {
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
    
    vector<int> preorder3(Node* root) {
        vector<int> result, res;
        if (root) {
            res.push_back(root->val);
            vector<int> vec;
            for (auto child : root->children) {
                vec = preorder(child);
                res.insert(res.end(), vec.begin(), vec.end());
            }
            result.insert(result.end(), res.begin(), res.end());
        }
        return result;
    }
    
    vector<int> preorder(Node* root) {
        stack<Node*> s; s.push(root);
        vector<int> result;
        while (!s.empty() && root) {
            Node * node = s.top(); s.pop();
            result.push_back(node->val);
            reverse(node->children.begin(), node->children.end());
            for (auto ch : node->children) s.push(ch);
        }
        return result;
    }
};
