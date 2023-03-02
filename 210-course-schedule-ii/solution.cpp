class Solution {
public:
    vector<vector<int>> graphs;
    vector<bool> visited;
    vector<bool> onpath;
    vector<int> poster_order;
    bool cycle;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graphs = build_graph(numCourses, prerequisites);

        visited = vector<bool>(numCourses, false);
        onpath = vector<bool>(numCourses, false);
        cycle = false;

        for (int i = 0; i < numCourses; i++) {
            dfs(i);
        }

        if (cycle) {
            return vector<int>();
        }

        reverse(poster_order.begin(), poster_order.end());
        return poster_order;
    }

    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graphs(numCourses);
        for (const auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            graphs[from].push_back(to);
        }
        return graphs;
    }

    void dfs(int src) {
        if (onpath[src]) {
            cycle = true;
        }

        if (visited[src] || cycle) {
            return;
        }

        visited[src] = true;
        onpath[src] = true;

        for (const auto& n : graphs[src]) {
            dfs(n);
        }

        poster_order.push_back(src);
        onpath[src] = false;
    }
};
