class Solution {
public:      
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        this->n = n;
        this->minProfit = minProfit;
        this->group = group;
        this->profits = profit;
        this->memo = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return find(0, 0, 0);
    }

private:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    
    int n;
    int minProfit;
    vector<int> group;
    vector<int> profits;

    int find(int pos, int count, int profit) {
        if (pos == group.size()) {
            // If profit exceeds the minimum required; it's a profitable scheme.
            return profit >= minProfit;
        }
        
        if (memo[pos][count][profit] != -1) {
            // Repeated subproblem, return the stored answer.
            return memo[pos][count][profit];
        }
        
        // Actions: commit this crime or skip it
        // Action 1: skip this crime
        int counts = find(pos + 1, count, profit);
        // Action 2: commit this crime
        if (count + group[pos] <= n) {
            // Adding ways to get profitable schemes, including this crime.
            counts += find(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]));
        }
        return memo[pos][count][profit] = counts % mod;
    }
};
