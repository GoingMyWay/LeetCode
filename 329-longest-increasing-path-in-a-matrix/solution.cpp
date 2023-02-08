class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        m = matrix.size(), n = matrix[0].size();
        cache = vector<vector<int>>(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (cache[i][j] != 0) return cache[i][j];
        for (auto const & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j]) {
                cache[i][j] = max(cache[i][j], dfs(matrix, x, y));
            }
        }
        return ++cache[i][j];
    }

private:
    int m, n;
    vector<vector<int>> dirs = {
                {-1, 0},
        {0, -1},        {0, 1},
                {1, 0}
    };
    vector<vector<int>> cache;
};
