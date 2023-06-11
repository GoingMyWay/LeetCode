class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;
        int pathLen = 1;

        vector<vector<int>> dirs = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0},
                {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };
        while (!q.empty()) {
            int sz = q.size();
            for (int __ = 0; __ < sz; __++) {
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second;
                if (x == m - 1 && y == n - 1) {
                    return pathLen;
                }
                for (int i = 0; i < 8; i++) {
                    int nextX = x + dirs[i][0];
                    int nextY = y + dirs[i][1];
                    if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n
                            && grid[nextX][nextY] == 0 && !visited[nextX][nextY]) {
                        q.push({nextX, nextY});
                        visited[nextX][nextY] = true;
                    }
                }
            }
            pathLen++;
        }
        return -1;
    }
};