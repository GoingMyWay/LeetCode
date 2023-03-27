class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dp(m - 1, n - 1, grid, memo);
    }

private:
    int dp(int x, int y, vector<vector<int>> & grid, vector<vector<int>> & memo) {
        if (x == 0 && y == 0) return grid[x][y];
        if (x < 0 || y < 0) return INT_MAX;
        if (memo[x][y] > 0) return memo[x][y];
        memo[x][y] = min(dp(x-1, y, grid, memo), dp(x, y-1, grid, memo)) + grid[x][y];
        return memo[x][y];
    }
};
