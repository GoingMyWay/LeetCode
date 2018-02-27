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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> hashMap;
        vector<int> vec, result;
        
        if ( NULL == root ) return result;
        visit(root, hashMap);
        
        for ( auto it: hashMap ) vec.push_back(it.second);
        int maxCount = *max_element(vec.begin(), vec.end());
        
        for ( auto it: hashMap ) {
            if ( maxCount == it.second ) result.push_back(it.first);
        }
        return result;
    }
    
    void visit(TreeNode * node, unordered_map<int, int> & Map) {
        if ( NULL != node ) {
            int res = nodeSum(node);
            if ( Map.count(res) ) Map[res] += 1;
            else Map[res] = 1;
            
            visit(node->left, Map);
            visit(node->right, Map);
        }
    }
    
    int nodeSum(TreeNode * node) {
        if ( NULL == node->left && NULL == node->right ) {
            return node->val;
        } else {
            return node->val + (NULL!=node->left ? nodeSum(node->left):0) + (NULL!=node->right ? nodeSum(node->right):0);
        }
    }
};

