class State {
public:
    int id;
    int distFromStart;
    State (int id, int distFromStart) {
        this->id = id;
        this->distFromStart = distFromStart;
    }
};


class ComparisonClass {
public:
    bool operator() (const State l, const State r) const { 
        return l.distFromStart > r.distFromStart; 
    }
};


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        graph[0] = {};
        for (vector<int> edge: times) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].push_back({to, weight});
        }

        vector<int> distTo = dijkstra(k, graph);

        int res = 0;
        for (int i = 1; i < distTo.size(); i++) {
            if (distTo[i] == INT_MAX) {
                return -1;
            }
            res = res > distTo[i] ? res: distTo[i];
        }
        return res;
    }

    vector<int> dijkstra(int start, vector<vector<pair<int, int>>> & graph) {
        vector<int> distTo(graph.size(), INT_MAX);
        distTo[start] = 0;

        priority_queue<State, vector<State>, ComparisonClass> pq;

        pq.push(State(start, 0));

        while (pq.size() > 0) {
            State curState = pq.top(); pq.pop();
            int curNodeID = curState.id;
            int curDisFromStart = curState.distFromStart;
            if (curDisFromStart > distTo[curNodeID]) {
                continue;
            }
            for (pair<int, int> neighbor: graph[curNodeID]) {
                int nextNodeID = neighbor.first;
                int distToNextNode = distTo[curNodeID] + neighbor.second;
                if (distToNextNode < distTo[nextNodeID]) {
                    distTo[nextNodeID] = distToNextNode;
                    pq.push(State(nextNodeID, distToNextNode));
                }
            }
        }
        return distTo;
    }
};