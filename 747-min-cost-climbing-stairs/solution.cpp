class Solution {
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
