class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int upper_bound = 0, lower_bound = m - 1;
        int left_bound = 0, right_bound = n - 1;

        while (res.size() < m * n) {
            // left -> right
            if (upper_bound <= lower_bound) {
                for (int j = left_bound; j <= right_bound; j++) {
                    res.push_back(matrix[upper_bound][j]);
                }
                upper_bound++;
            }
            // up -> down
            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) {
                    res.push_back(matrix[i][right_bound]);
                }
                right_bound--;
            }

            // right -> left
            if (upper_bound <= lower_bound) {
                for (int j = right_bound; j >= left_bound; j--) {
                    res.push_back(matrix[lower_bound][j]);
                }
                lower_bound--;
            }

            // down -> up
            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    res.push_back(matrix[i][left_bound]);
                }
                left_bound++;
            }
        }
        return res;
    }
};