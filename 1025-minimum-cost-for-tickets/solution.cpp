class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        return dp(0, memo, days, costs);
    }

private:
    int dp(int i, vector<int>& memo, vector<int>& days, vector<int>& costs) {
        if (i >= days.size()) return 0;
        if (memo[i] != -1) return memo[i];

        vector<int> nextDays(3, -1);
        vector<int> durations = {1, 7, 30};
        for (int k = 0; k < 3; k ++) {     
            int j = i;
            while (j < days.size() && days[j] < days[i] + durations[k]) j ++;
            nextDays[k] = j;
        }
        ans = min({ans,
                   dp(nextDays[0], memo, days, costs) + costs[0],
                   dp(nextDays[1], memo, days, costs) + costs[1],
                   dp(nextDays[2], memo, days, costs) + costs[2],
        });
        memo[i] = ans;
        return ans;
    }
    
    int ans = INT_MAX;
};
