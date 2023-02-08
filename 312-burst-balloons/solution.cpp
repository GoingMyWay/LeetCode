class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> points(n+2, 1);
        // for (int i = 1; i <= n; i++) {
        //     points[i] = nums[i-1];
        // }
        // vector<vector<int>> dp(n+2, vector<int>(n+2));
        // for (int i = n; i >= 0; i--) {
        //     for (int j = i + 1; j < n + 2; j++) {
        //         for (int k = i + 1; k < j; k ++) {
        //             dp[i][j] = max(
        //                 dp[i][j],
        //                 dp[i][k]+dp[k][j]+points[i]*points[j]*points[k]
        //             );
        //         }
        //     }
        // }
        // return dp[0][n+1];

        int size = nums.size() + 2;
        vector<int> points(size);
        points[0] = points[size-1] = 1;
        for(int i = 0; i < nums.size(); i++) {
            points[i+1] = nums[i];
        }
        vector<vector<int>> memo(size, vector<int>(size));

        int result = dp(points, memo, 0, size-1);    
        return result;
    }

    int dp(vector<int>& points, vector<vector<int>>& memo, int left, int right) {
        // base case
        if (left + 1 == right) {
            return 0;
        }

        if (memo[left][right] > 0) {
            return memo[left][right];
        }
        
        // find max
        int currMax = 0;
        int pointsBase = points[left] * points[right];
        for(int i = left + 1; i < right; i++) {
            currMax = max(
                currMax, 
                points[i]*pointsBase + dp(points, memo, left, i) + dp(points, memo, i, right)
            );
        }
        memo[left][right] = currMax;
        return currMax;
    }
};
