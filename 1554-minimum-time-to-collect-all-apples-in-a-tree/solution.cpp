class Solution {
public:
    int res = 0;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        vector<bool> beConnected(n, false);
        for (int i = 0; i < edges.size(); i ++) {
            // process the case like this: {(0, 2), (0, 3), (1, 2)}
            if (edges[i][1] > edges[i][0] && beConnected[edges[i][1]] && adj[edges[i][1]].size() == 0) {
                adj[edges[i][1]].push_back(edges[i][0]);
                beConnected[edges[i][0]] = true;
            } else {
                adj[edges[i][0]].push_back(edges[i][1]);
                beConnected[edges[i][1]] = true;
            }
        }
        dfs(adj, 0, hasApple);
        return res;
    }

    bool dfs(vector<vector<int>>& adj, int i, vector<bool>& hasApple) {
        if (adj[i].size() == 0) return hasApple[i];

        bool appleVisited = false;
        for (int j = 0; j < adj[i].size(); j ++) { // visit child nodes
            bool flag = dfs(adj, adj[i][j], hasApple);
            if (j == 0 && flag) appleVisited = true;
            if (flag) res += 2;
            appleVisited = appleVisited || flag;
        }
        // either the current node has apples in its sub-tree or there is an apple in the current node
        return appleVisited || hasApple[i];
    }
};
