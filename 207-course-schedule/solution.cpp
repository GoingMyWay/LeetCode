class Solution {
public:
    vector<vector<int>> graphs;
    vector<bool> visited, onpath;
    bool cycle;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graphs = build_graph(numCourses, prerequisites);
        
        // define variables
        visited.assign(numCourses, false);
        onpath.assign(numCourses, false);
        cycle = false;

        for (int node = 0; node < numCourses; node++) {
            dfs(node);
        }

        return !cycle;
    }

    vector<vector<int>> build_graph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graphs(numCourses, vector<int>());
        for (const auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            graphs[from].push_back(to);
        }
        return graphs;
    }

    void dfs(int src) {
        if (onpath[src]) {
            cycle = true;
            return;
        }
        if (visited[src] || cycle) {
            return;
        }

        visited[src] = true;
        onpath[src] = true;

        for (const auto& n : graphs[src]) {
            dfs(n);
        }

        onpath[src] = false;
    }
};
