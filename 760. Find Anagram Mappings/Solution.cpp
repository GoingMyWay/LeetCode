class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> hash_map;
        for (int i = 0; i < B.size(); i ++) {
            hash_map.insert(pair<int, int>(B[i], i));
        }
        vector<int> result;
        for (int i = 0; i < A.size(); i ++) {
            result.push_back(hash_map[A[i]]);
        }
        return result;
    }
};