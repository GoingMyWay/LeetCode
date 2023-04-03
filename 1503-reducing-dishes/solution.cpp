class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        // Mark all the states initially as 0.
        vector<vector<int>> dp(satisfaction.size() + 1, 
                               vector<int>(satisfaction.size() + 2, 0)
        );
        for (int i = satisfaction.size() - 1; i >= 0; i --) {
            for (int t = 1; t <= satisfaction.size(); t ++) {
                // Maximum of two choices:
                // 1. Cook the dish at `index` with the time taken as `time` 
                //    and move on to the next dish with time as time + 1.
                // 2. Skip the current dish and move 
                //    on to the next dish at the same time.
                dp[i][t] = max(satisfaction[i] * t + dp[i + 1][t + 1], 
                               dp[i + 1][t]);
            }
        }
        return dp[0][1];
    }
};
