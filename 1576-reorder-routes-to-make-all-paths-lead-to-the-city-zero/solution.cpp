class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<set<int>> adj(n);
        vector<set<int>> dummyAdj(n);
        for (auto conn : connections) {
            adj[conn[0]].insert(conn[1]);
            dummyAdj[conn[0]].insert(conn[1]);
            dummyAdj[conn[1]].insert(conn[0]);
        }

        vector<int> visited(n, false);

        queue<int> q;
        q.push(0);
        int res = 0;
        while (q.size() > 0) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i ++) {
                int node = q.front(); q.pop();
                visited[node] = true;
                for (int adjNode : dummyAdj[node]) {
                    if (!visited[adjNode]) {
                        // check adjNode -> node is found
                        if (adj[node].find(adjNode) != adj[node].end()) {
                            res += 1;
                        }
                        q.push(adjNode);
                    }
                }
            }
        }
        return res;
    }
};