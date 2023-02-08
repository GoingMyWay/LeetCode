class Solution {
public:
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size(); // m*n matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Every element of priority queue has 3 int values:
        // 1. Max height of boundary current element provides
        // 2. X axis of current element
        // 3. Y axis of current element
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> boundary;
        
        for(int i = 0; i < m; ++i) {
            boundary.push({heightMap[i][0], i, 0});
            boundary.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        
        for(int j = 0; j < n; ++j) {
            boundary.push({heightMap[0][j], 0, j});
            boundary.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        
        int totalWater = 0;
        int directions[4][2] = {
                    {-1, 0},
            {0, -1},       {0, 1},  
                    {1, 0},
        };
        while(!boundary.empty()) {
            vector<int> curr = boundary.top();
            boundary.pop();
            
            for(int i = 0; i < 4; ++i) {
                int x = curr[1] + directions[i][0];
                int y = curr[2] + directions[i][1];
                
                if(0 <= x && x <= m-1 && 0 <= y && y <= n-1 && !visited[x][y]){
                    totalWater += max(0, curr[0] - heightMap[x][y]);
                    boundary.push({max(curr[0], heightMap[x][y]), x, y});
                    visited[x][y] = true;
                }
            }
        }
        
        return totalWater;
    }
};