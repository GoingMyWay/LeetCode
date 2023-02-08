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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // return dfsSolution(isConnected);
        return ufSolution(isConnected);
    }

    int ufSolution(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (isConnected[i][j] == 1) uf.union_(i, j);
            }
        }
        return uf.getCount();
    }

    int dfsSolution(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visited = vector<bool>(n);
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (!visited[i]) {
                dfs(i, isConnected);
                count += 1;
            }
        }
        return count;
    }

    void dfs(int i, vector<vector<int>>& isConnected) {
        if (visited[i]) return;

        visited[i] = true;
        for (int w = 0; w < n; w ++) {
            if (isConnected[i][w] == 1) {
                dfs(w, isConnected);
            }
        }
    }

private:
    vector<bool> visited;
    int n;
};