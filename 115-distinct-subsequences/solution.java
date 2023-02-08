class Solution {
    public int numDistinct(String s, String t) {
        memo = new int[s.length()][t.length()];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return dp(s, 0, t, 0);
    }

    int[][] memo;

    // 定义：该函数返回 s[i..] 中的子序列 t[j..] 的数量
    int dp(String s, int i, String t, int j) {
        int m = s.length(), n = t.length();
        if (j == n) {
            // 子序列全部匹配完成
            return 1;
        }
        if (n - j > m - i) {
            // 待匹配子序列的长度不应该比字符串的长度还要短
            return 0;
        }
        if (memo[i][j] != -1) {
            // 已经计算过对应状态
            return memo[i][j];
        }
        int res = 0;
        // 状态转移方程
        if (s.charAt(i) == t.charAt(j)) {
            res += dp(s, i + 1, t, j + 1) + dp(s, i + 1, t, j);
        } else {
            res += dp(s, i + 1, t, j);
        }
        memo[i][j] = res;
        return res;
    }
}
