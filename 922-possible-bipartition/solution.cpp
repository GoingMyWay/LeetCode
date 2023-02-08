class Solution {
public:
    bool ok = true;
    vector<bool> colors;
    vector<bool> visited;
    queue<int> q;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph = buildGraph(n, dislikes);
        return isBipartite(graph);
    }

    vector<vector<int>> buildGraph(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (auto vs: dislikes) {
            graph[vs[0]-1].push_back(vs[1]-1);
            graph[vs[1]-1].push_back(vs[0]-1);
        }
        return graph;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        colors = vector<bool>(n, false);
        visited = vector<bool>(n, false);
        for (int i = 0; i < n; i ++) {
            if (!visited[i])
                // dfs(i, graph);
                bfs(i, graph);
        }
        return ok;
    }

    void bfs(int node, vector<vector<int>>& graph) {
        visited[node] = true;
        q.push(node);
        
        while (q.size() && ok) {
            int v = q.front(); q.pop();
            for (int w : graph[v]) {
                if (!visited[w]) {
                    colors[w] = !colors[v];
                    visited[w] = true;
                    q.push(w);
                } else {
                    if (colors[w] == colors[v]) {
                        ok = false;
                        return;
                    }
                }
            }
        }
    }

    void dfs(int v, vector<vector<int>>& graph) {
        if (!ok) return;

        visited[v] = true;
        for (int w: graph[v]) {
            if (!visited[w]) {
                colors[w] = !colors[v];
                dfs(w, graph);
            } else {
                if (colors[w] == colors[v]) ok = false;
            }

        }
    }

};
