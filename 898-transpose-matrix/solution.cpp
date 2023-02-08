class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<int> col(A.size());
        vector<vector<int>> result(A[0].size(), col);
        for (int i = 0; i < A.size(); i ++) {
            for (int j = 0; j < A[0].size(); j ++) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};
