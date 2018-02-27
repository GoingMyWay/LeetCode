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
        if ( NULL == node ) {
            return 0;
        } else {
            return node->val + nodeSum(node->left) + nodeSum(node->right);
        }
    }
};
class Solution2 {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        int maxCount = 0;
        
        nodeSum(root, hashMap, maxCount);
        for ( auto it: hashMap ) {
            if ( maxCount == it.second ) result.push_back(it.first);
        }
        return result;
    }
    
    int nodeSum(TreeNode * node, unordered_map<int, int> & Map, int & cnt) {
        if ( NULL == node ) {
            return 0;
        } else {
            int left = nodeSum(node->left, Map, cnt);
            int right = nodeSum(node->right, Map, cnt);
            int res = left + right + node->val;
            cnt = max(cnt, ++Map[res]);
            return res;
        }
    }
};
