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
    vector<int> postorder(Node* root) {
        vector<int> result, vec, temp;
        if (root) {
            for (auto child : root->children) {
                temp = postorder(child);
                vec.insert(vec.end(), temp.begin(), temp.end());
            }
            result.insert(result.end(), vec.begin(), vec.end());
            result.push_back(root->val);
        }
        return result;
    }
    
    vector<int> postorder2(Node* root) {
        stack<Node*> s; s.push(root);
        vector<int> result;
        while (!s.empty() && root) {
            Node * n = s.top(); s.pop();
            result.insert(result.begin(), n->val);
            for (auto child : n->children) s.push(child);
        }
        return result;
    }
};
