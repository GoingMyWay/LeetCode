class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);

        for (int i = 0; i < edges.size(); i ++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double weight = succProb[i];
            graph[from].push_back({weight, to});
            graph[to].push_back({weight, from});
        }
        return dijkstra(start, end, graph);
    }

    double dijkstra(int start, int end, vector<vector<pair<double, int>>> & graph) {
        int v = graph.size();
        vector<double> distTo(v, 0);
        distTo[start] = 1;

        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.push({1.0, start});

        while (pq.size() > 0) {
            pair<double, int> curState = pq.top(); pq.pop();
            int curNodeID = curState.second;
            double curDistFromStart = curState.first;

            if (curNodeID == end) {
                return curDistFromStart;
            }

            if (curDistFromStart < distTo[curNodeID]) {
                continue;
            }

            for (pair<double, int> & neighbor: graph[curNodeID]) {
                int nextNodeID = neighbor.second;
                double distToNextNode = distTo[curNodeID] * neighbor.first;
                if (distToNextNode > distTo[nextNodeID]) {
                    distTo[nextNodeID] = distToNextNode;
                    pq.push({distToNextNode, nextNodeID});
                } 
            }
        }
        return 0.0;
    }
};
