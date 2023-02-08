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

bool compare (vector<int> edge1, vector<int> edge2) { return (edge1[2] < edge2[2]); }

class ComparisonClass {
public:
    bool operator() (const pair<int, pair<int, int>> l, const pair<int, pair<int, int>> r) const { 
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        vector<vector<pair<int, pair<int, int>>>> g(n);
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                edges.push_back({abs(x1-x2)+abs(y1-y2), {i, j}});
                g[i].push_back({abs(x1-x2)+abs(y1-y2), {i, j}});
                g[j].push_back({abs(x1-x2)+abs(y1-y2), {j, i}});
            }
        }
        // return minimumCost(n, edges);
        return primMininumCost(g);
    }

    int primMininumCost(vector<vector<pair<int, pair<int, int>>>> g) {
        Prim prim(g);
        if (!prim.allConnected()) {
            return -1;
        }
        return prim.getWeightSum();
    }

    int minimumCost(int n, vector<pair<int, pair<int, int>>>& connections) {
        UF uf(n);
        int newEdges = 0;
        sort(connections.begin(), connections.end()); // use vector<pair<int, pair<int, int>>> can be faster in sort
        int mst = 0;
        for (int i = 0; i < connections.size() & newEdges < n - 1; i ++) {
            int weight = connections[i].first;
            int node1 = connections[i].second.first;
            int node2 = connections[i].second.second;
            if (uf.connect(node1, node2)) {
                continue;
            }
            mst += weight;
            uf.union_(node1, node2);
            newEdges += 1;
        }
        return uf.getCount() == 1 ? mst : -1;
    }
};
