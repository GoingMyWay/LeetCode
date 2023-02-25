class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));

        queue<vector<int>> q;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (q.size() > 0) {
            auto cur = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i ++) {
                int newx = x + dirs[i][0], newy = y + dirs[i][1];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && res[newx][newy] == -1) {
                    q.push({newx, newy});
                    res[newx][newy] = res[x][y] + 1;
                }
            }
        }
        return res;
    }
};