class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < int(grid.size())-2; i ++) {
            for (int j = 0; j < int(grid[0].size())-2; j ++)  {
                if (grid[i+1][j+1] != 5) continue;
                
                if (magic(grid[i][j], grid[i][j+1], grid[i][j+2], 
                          grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                          grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]))
                    result ++;
            }
        }
        return result;
    }
    
    int magic(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
        vector<int> v = {a, b, c, d, e, f, g, h, i};
        sort(v.begin(), v.end());
        for (int i = 1; i <= 9; i ++)
            if (v[i-1] != i) return 0;
        
        return a+b+c == 15 && 
               d+e+f == 15 && 
               g+h+i == 15 && 
               a+d+g == 15 && 
               b+e+h == 15 && 
               c+f+i == 15 && 
               a+e+i == 15 && 
               c+e+g == 15;   
    }
};
