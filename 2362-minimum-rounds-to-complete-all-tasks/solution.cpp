class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for (auto v: tasks) {
            m[v] += 1;
        }
        int res = 0;
        for (auto const & [k, v]: m) {
            if (v == 1) return -1;
            if (v % 3 == 0) res += v / 3;
            else res += v / 3 + 1;
        }
        return res;
    }
};
