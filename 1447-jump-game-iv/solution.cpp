class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> visited;
        unordered_map<int, vector<int>> valueToIndex(n);
        for (int i = 0; i < arr.size(); i ++) valueToIndex[arr[i]].push_back(i);

        queue<int> q;
        q.push(0);
        visited.insert(0);
        int step = 0, qsize = 0;
        while (q.size() > 0) {
            qsize = q.size();
            for (int i = 0; i < qsize; i ++) {
                auto node = q.front(); q.pop();
                if (node == n - 1) return step;

                for (auto v : valueToIndex[arr[node]]) {
                    if (visited.find(v) == visited.end()) {
                        q.push(v);
                    }
                    visited.insert(v);
                }

                valueToIndex[arr[node]].clear(); // reduce the time cost

                if (node + 1 < arr.size() && visited.find(node + 1) == visited.end()) {
                    q.push(node + 1);
                    visited.insert(node + 1);
                }
                if (node - 1 >= 0 && visited.find(node - 1) == visited.end()) {
                    q.push(node - 1);
                    visited.insert(node - 1);
                }
            }
            step ++;
        }
        return -1;
    }
};
