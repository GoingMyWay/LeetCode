class Solution {
    public:
    // 备忘录，-1 代表还未计算，0 代表 false，1 代表 true
    vector<vector<int>> memo;

    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        // 将 p 中相邻的 * 去除，以提升效率
        string pp = remove_adj_star(p);
        int m = s.size(), n = pp.size();
        // 备忘录初始化为 -1
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        // 执行自顶向下带备忘录的动态规划
        return dp(s, 0, pp, 0);
    }

    // 删除相邻的 * 号，返回删除后的字符
    string remove_adj_star(string p) {
        if (p.empty()) {
            return "";
        }
        string pp;
        pp.push_back(p[0]);
        for (int i = 1; i < p.size(); i++) {
            if (p[i] == '*' && p[i - 1] == '*') {
                continue;
            }
            pp.push_back(p[i]);
        }
        return pp;
    }

    // 定义：判断 s[i..] 是否能被 p[j..] 匹配
    bool dp(string& s, int i, string& p, int j) {
        // base case
        if (j == p.size() && i == s.size()) {
            return true;
        }
        if (i == s.size()) {
            for (int k = j; k < p.size(); k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (j == p.size()) {
            return false;
        }
        if (memo[i][j] != -1) {
            return bool(memo[i][j]);
        }

        bool res = false;
        if (s[i] == p[j] || p[j] == '?') {
            // s[i] 和 p[j] 完成匹配
            res = dp(s, i + 1, p, j + 1);
        } else if (p[j] == '*') {
            // s[i] 和 p[j] 不匹配，但 p[j] 是通配符 *
            // 可以匹配 0 个或多个 s 中的字符，
            // 只要有一种情况能够完成匹配即可
            res = dp(s, i + 1, p, j)
                    || dp(s, i, p, j + 1);
        }
        // 将 s[i] 和 p[j] 的匹配结果存储备忘录
        memo[i][j] = res;

        return res;
    }
};