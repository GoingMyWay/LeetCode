class Solution {
public:
    vector<int> child[100001];
    int ans;
    int dfs(string &s, int i) {
        if (child[i].size() == 0) return 1;
        int mx1 = 0, mx2 = 0;
        for (auto const & child_i : child[i]) {
            int len = dfs(s, child_i);
            ans = max(ans , len);
            if (s[i] == s[child_i]) continue;
            if (len > mx1) {
                mx2 = mx1;
                mx1 = len;
            } else mx2 = max(mx2 , len);
        }
        ans = max(ans, 1 + mx1 + mx2);
        return 1 + mx1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        for (int i = 1; i < n; i++) child[parent[i]].push_back(i);
        ans = 1;
        dfs(s, 0);
        return ans;
    }
};
