class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        // 如果长度对不上，必然不可能
        if (m + n != s3.length()) return false;
        // 备忘录，其中 -1 代表未计算，0 代表 false，1 代表 true
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dp(s1, 0, s2, 0, s3);
    }

private:
    vector<vector<int>> memo;

    // 定义：计算 s1[i..] 和 s2[j..] 是否能组合出 s3[i+j..]
    bool dp(string& s1, int i, string& s2, int j, string& s3) {
        int k = i + j;
        // base case，s3 构造完成
        if (k == s3.length()) return true;
        // 查备忘录，如果已经计算过，直接返回
        if (memo[i][j] != -1) return (int)memo[i][j];

        bool res = false;
        // 如果，s1[i] 可以匹配 s3[k]，那么填入 s1[i] 试一下
        if (i < s1.length() && s1[i] == s3[k]) {
            res = dp(s1, i + 1, s2, j, s3);
        }
        // 如果，s1[i] 匹配不了，s2[j] 可以匹配，那么填入 s2[j] 试一下
        if (j < s2.length() && s2[j] == s3[k]) {
            res = res || dp(s1, i, s2, j + 1, s3);
        }
        // 如果 s1[i] 和 s2[j] 都匹配不了，则返回 false
        // 将结果存入备忘录
        memo[i][j] = (int)res;
        return res;
    }
};
