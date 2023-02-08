class Solution {
public:
    int countPaths(vector<vector<int>>& matrix) {
        if (matrix.size() ==  0) return 0;
        m = matrix.size(), n = matrix[0].size();
        cache = vector<vector<long>>(m, vector<long>(n, -1));
        long res = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                res = (res + dfs(matrix, i, j)) % MOD;
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (cache[i][j] != -1) return cache[i][j];
        long res = 1;
        for (auto const & dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j]) {
                res = (res + dfs(matrix, x, y)) % MOD;
            }
        }
        return cache[i][j] = res;
    }

private:
    int m, n;
    const long MOD = 1e9+7;
    vector<vector<int>> dirs = {
                {-1, 0},
        {0, -1},        {0, 1},
                {1, 0}
    };
    vector<vector<long>> cache;
};
