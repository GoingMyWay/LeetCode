class UnionFind {
public:
    UnionFind(int n) {
        count = n;
        parent = vector<int>(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        count -= 1;
    }

    bool connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getCount() {
        return count;
    }

private:
    int count;
    vector<int> parent;
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // return dfsSolution(n, edges);
        return ufSolution(n, edges);
    }

    int ufSolution(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto vs: edges) {
            uf.union_(vs[0], vs[1]);
        }
        return uf.getCount();
    }

    int dfsSolution(int n, vector<vector<int>>& edges) {
        visited = vector<bool>(n);
        int count = 0;
        vector<vector<int>> graph = buildGraph(n, edges);
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                dfs(i, graph);
                count += 1;
            }
        }
        return count;
    }

    void dfs(int i, vector<vector<int>>& graph) {
        if (visited[i]) return;

        visited[i] = true;
        for (int w: graph[i]) {
            dfs(w, graph);
        }
    }

    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto vs: edges) {
            graph[vs[0]].push_back(vs[1]);
            graph[vs[1]].push_back(vs[0]);
        }
        return graph;
    }

private:
    vector<bool> visited;
};