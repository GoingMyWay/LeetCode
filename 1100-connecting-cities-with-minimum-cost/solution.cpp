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


bool compare (vector<int> edge1, vector<int> edge2) { 
    return edge1[2] < edge2[2]; 
}


class ComparisonClass {
public:
    bool operator() (const pair<int, pair<int, int>> l,
                     const pair<int, pair<int, int>> r) const { 
        return l.first > r.first; 
    }
};


class Prim {
public:
    Prim (vector<vector<pair<int, pair<int, int>>>> g) {
        graph = g;
        int n = graph.size();  // number of nodes
        inMST = vector<bool>(n);
        inMST[0] = true;
        cut(0); // start from the first node
        while (pq.size() > 0) {
            pair<int, pair<int, int>> edge = pq.top(); pq.pop();
            int to = edge.second.second;
            int weight = edge.first;
            if (inMST[to]) {
                continue;
            }
            weightSum += weight;
            inMST[to] = true;
            cut(to);
        }
    }

    void cut(int s) {
        for (pair<int, pair<int, int>> edge: graph[s]) {
            int to = edge.second.second;
            if (inMST[to]) {
                continue;
            }
            pq.push(edge);
        }
    }

    int getWeightSum() {
        return weightSum;
    }

    bool allConnected() {
        for (int i = 0; i < inMST.size(); i ++) {
            if (!inMST[i]) {
                return false;
            }
        }
        return true;
    }

private:
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, ComparisonClass> pq;
    vector<vector<pair<int, pair<int, int>>>> graph;
    int weightSum = 0;
    vector<bool> inMST;
};


class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // return solution(n, connections);
        return primSolution(n, connections);
    }

    int solution(int n, vector<vector<int>> & connections) {
        UF uf(n);
        sort(connections.begin(), connections.end(), compare);
        int mst = 0;
        for (auto edge: connections) {
            if (uf.connect(edge[0]-1, edge[1]-1)) {
                continue;
            }
            mst += edge[2];
            uf.union_(edge[0]-1, edge[1]-1);
        }
        return uf.getCount() == 1 ? mst : -1;
    }

    int primSolution(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, pair<int, int>>>> g(n);
        for (auto edge: connections) {
            int v = edge[0]-1, w = edge[1]-1, weight = edge[2];
            g[v].push_back({weight, {v, w}});
            g[w].push_back({weight, {w, v}});
        }

        Prim prim(g);

        if (!prim.allConnected()) {
            return -1;
        }
        return prim.getWeightSum();
    }
};
