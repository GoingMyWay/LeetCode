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

    vector<int> getNodeCounts() {
        int n = parents.size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i ++) res[find(i)] += 1;

        return res;
    }

private:
    int n;
    vector<int> parents;
};


class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        UF uf(n);
        for (auto connection : edges)
            uf.unionNodes(connection[0], connection[1]);
        
        int connectedGraphCounts = uf.getConnectedGraphCounts();
        if (connectedGraphCounts == 1) return 0;
        
        vector<int> nodeCounts = uf.getNodeCounts();
        long long res = 0, remains = n;
        for (int i = 0; i < nodeCounts.size(); i ++) {
            if (nodeCounts[i] == 0) continue;
            res += nodeCounts[i] * (remains - nodeCounts[i]);
            remains -= nodeCounts[i];
        }
        return res;
    }
};
