class UF {
public:
    UF(int n) {
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

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
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
    bool validTree(int n, vector<vector<int>>& edges) {
        UF uf(n);

        for (auto edge: edges) {
            if (!uf.connect(edge[0], edge[1])) {
              uf.union_(edge[0], edge[1]);
            } else {
                return false;
            }
        }
        return uf.getCount() == 1;
    }
};
