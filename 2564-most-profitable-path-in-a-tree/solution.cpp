class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        // return solution1(edges, bob, amount);
        return solution2(edges, bob, amount);
    }

private:
    // Solution 1
    vector<int> par, dis;

    int solution1(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n, vector<int>());
        for (auto const & e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        updateDistanceAndParent(0);
        updateAmount(bob, amount);
        return dfs(0, amount);
    }

    // update amount via simulating the visit of Bob from its node to node 0.
    void updateAmount(int bob, vector<int>& amount) {
        int cur = bob;
        int bob_dis = 0;
        while (cur != 0) {
            if (dis[cur] > bob_dis) {
                amount[cur] = 0; // visted only by Bob
            } else if (dis[cur] == bob_dis) {
                amount[cur] /= 2; // meet with Alice at at this node at the same time
            }
            cur = par[cur];
            bob_dis ++;
        }
    }

	// find the parent and distance from node 0
    void updateDistanceAndParent(int u, int p = 0, int d = 0) {
        dis[u] = d;
        par[u] = p;
        for (int v: adj[u]) {
            if (v == p) continue;
            updateDistanceAndParent(v, u, d+1);
        }
    }

	// find total sum to each node
    int dfs(int u, vector<int>& amount, int p = 0) {
        int ret = amount[u];
        int mxc = -INT_MAX;
        for (int v : adj[u]) {
            if (v != p) {
                mxc = max(mxc, dfs(v, amount, u));
            }
        }
		// if the node is leaf we just return its amount
        if (mxc == -INT_MAX) return ret;
        else return ret+mxc;
    }

    // Solution 2
    vector<vector<int>> adj;
    vector<int> disFromBob;
    int bobNode;
    int dfs2(int u, int par, int depth, vector<int>& amount) {
        int ret = 0;
        if (u == bobNode) disFromBob[u] = 0;
        else disFromBob[u] = amount.size();
        int maxChild = -INT_MAX;
        for (int v : adj[u]) {
            if (v == par) continue;
            maxChild = max(maxChild, dfs2(v, u, depth+1, amount));
            disFromBob[u] = min(disFromBob[u], disFromBob[v]+1);
        }
        if (disFromBob[u] > depth) ret += amount[u];
        else if (disFromBob[u] == depth) ret += amount[u] / 2;

        if (maxChild == -INT_MAX) return ret;
        else return ret + maxChild;
    }

    int solution2(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        bobNode = bob;
        adj.resize(n, vector<int>());
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        disFromBob.resize(n);
        return dfs2(0, 0, 0, amount);
    }
};
