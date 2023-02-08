class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sumVal = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sumVal % 4 != 0) return false;
        edgeVal = sumVal / 4;
        for (auto v : matchsticks) {
            if (v > edgeVal) return false;
        }
        sumv = vector<int>(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return dfs(0, matchsticks);
    }

private:
    int edgeVal = 0;
    vector<int> sumv;
    bool dfs(int index, vector<int>& matchsticks) {
        if (index == matchsticks.size()) {
            return sumv[0] == edgeVal && sumv[0] == sumv[1] && sumv[1] == sumv[2] && sumv[2] == sumv[3];
        }

        int val = matchsticks[index];
        for (int i = 0; i < 4; i ++) {
            if (sumv[i] + val <= edgeVal) {
                sumv[i] += val;
                if (dfs(index + 1, matchsticks)) {
                    return true;
                }
                // val cannot be assigned, so roll-back
                sumv[i] -= val;
            }
        }
        // tried all 4 edges, and the val cannot be assigned.
        return false;
    }
 };