// Bottom-Top Solution
class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = (int)cost.size();
        vector<int> dp(size);
        dp[0] = cost[0]; dp[1] = cost[1];
        
        for (int i=2; i < size; i ++ ) {
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);    
        }
        return min(dp[size-2], dp[size-1]);
    }
}; 

// Top-Bottom Solution
class Solution2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return topDownDP(cost, cost.size());
    }

    int topDownDP(vector<int>& c, int idx) {
        if ( 1 == dp.count(idx)) return dp[idx];
        if ( idx <= 1 ) return dp[idx] = c[idx];
        return dp[idx] = (idx == c.size() ? 0: c[idx]) + min(topDownDP(c, idx-1), topDownDP(c, idx-2));
    }

private:
    unordered_map<int, int> dp;
};

