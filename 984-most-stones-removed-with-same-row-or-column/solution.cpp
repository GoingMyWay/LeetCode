class UF {
public:
    UF(int n) : n (n) {
        parents = vector<int>(n, 0);
        for (int i = 0; i < n; i ++) {
            parents[i] = i;
        }
    }

    void unionNodes(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return;
        parents[rootI] = rootJ;
        n --;
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }

    vector<int> getNumofEachComponent() {
        int n = parents.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; i ++) res[find(i)] += 1;
        return res;
    }

    int getNComponent() {
        return n;
    }

private:
    int n;
    vector<int> parents;
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        this->n = stones.size();
        UF uf(n);
        unordered_map<int, vector<int>> xNodeIDs;
        unordered_map<int, vector<int>> yNodeIDs;
        for (int i = 0; i < n; i ++) {
            auto stone = stones[i];
            xNodeIDs[stone[0]].push_back(i);
            yNodeIDs[stone[1]].push_back(i);
        }

        for (auto const & [x, nodes] : xNodeIDs) {
            for (int i = 0; i < nodes.size() - 1; i ++) {
                uf.unionNodes(nodes[i], nodes[i + 1]);
            }
        }

        for (auto const & [y, nodes] : yNodeIDs) {
            for (int i = 0; i < nodes.size() - 1; i ++) {
                uf.unionNodes(nodes[i], nodes[i + 1]);
            }
        }

        // vector<int> numofEachComponent = uf.getNumofEachComponent();
        // int res = 0;
        // for (auto v : numofEachComponent) {
        //     if (v == 0 || v == 1) continue;
        //     res += v - 1;
        // }
        // return res;
        return n - uf.getNComponent();
    }

private:
    int n;
};