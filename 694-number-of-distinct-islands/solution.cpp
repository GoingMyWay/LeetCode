class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<string> islands;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    string s = "";
                    dfs(grid, i, j, s, 666);
                    islands.insert(s);
                }
            }
        }
        return islands.size();
    }

    void dfs(vector<vector<int>>& grid, int i, int j, string& s, int dir) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >=m || j >= n || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        s.push_back(char(dir));
        s.push_back(',');

        dfs(grid, i - 1, j, s, 1);
        dfs(grid, i + 1, j, s, 2);
        dfs(grid, i, j + 1, s, 3);
        dfs(grid, i, j - 1, s, 4);

        s.push_back(char(-dir));
        s.push_back(',');
    }

};