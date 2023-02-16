class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto const & v: redEdges) {
            adj[v[0]].push_back({v[1], 0});
        }
        for (auto const & v: blueEdges) {
            adj[v[0]].push_back({v[1], 1});
        }

        vector<int> answer(n, -1);
        answer[0] = 0;
        vector<vector<bool>> visit(n, vector<bool>(2));
        queue<vector<int>> q;

        q.push({0, 0, -1}); // node id, distance, default color
        visit[0] = {true, true};

        while (q.size() > 0) {
            auto nodeInfo = q.front(); q.pop();
            int node = nodeInfo[0], dist = nodeInfo[1], preColor = nodeInfo[2];

            for (auto const & [next, color]: adj[node]) {
                if (!visit[next][color] && color != preColor) {
                    visit[next][color] = true;
                    q.push({next, 1+dist, color});
                    if (answer[next] == -1) {
                        answer[next] = 1 + dist;
                    }
                }
            }
        }
        return answer;
    }
};
