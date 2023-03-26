class UF {

public:
    UF(int n) : n(n) {
        parents = vector<int>(n, 0);
        for (int i = 0; i < n; i ++) {
            parents[i] = i;
        }
    }

    void unionNodes(int i, int j) {
        int p = find(i);
        int q = find(j);
        if (p == q) return;
        parents[p] = q;
        n --;
    }

    int find(int i) {
        if (parents[i] != i) {
            int parent = find(parents[i]);
            parents[i] = parent;
        }
        return parents[i];
    }

    int getConnectedGraphCounts() {
        return n;
    }

    int getNodeCount() {
        return parents.size();
    }

private:
    int n;
    vector<int> parents;
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UF uf(n);
        for (auto connection : connections)
            uf.unionNodes(connection[0], connection[1]);
        
        int totalCalbles = connections.size();
        if (totalCalbles >= uf.getNodeCount() - 1) 
            return uf.getConnectedGraphCounts() - 1;
        else 
            return -1;
    }
};
