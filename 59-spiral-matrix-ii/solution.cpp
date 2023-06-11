class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int upper_bound = 0, lower_bound = n - 1;
        int left_bound = 0, right_bound = n - 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int count = 0;
        while (count < n*n) {
            // left -> right
            if (upper_bound <= lower_bound) {
                for (int j = left_bound; j <= right_bound; j++) {
                    matrix[upper_bound][j] = count + 1;
                    count++;
                }
                upper_bound++;
            }
            
            // up -> down
            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; i++) {
                    matrix[i][right_bound] = count + 1;
                    count++;
                }
                right_bound--;
            }
            
            // right -> left
            if (upper_bound <= lower_bound) {
                for (int j = right_bound; j >= left_bound; j--) {
                    matrix[lower_bound][j] = count + 1;
                    count++;
                }
                lower_bound--;
            }
            
            // down -> up
            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; i--) {
                    matrix[i][left_bound] = count + 1;
                    count++;
                }
                left_bound++;
            }
        }
        return matrix;
    }
};
