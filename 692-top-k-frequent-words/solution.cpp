class Solution {
using State = pair<int, string>;
public:
    struct comparator {
        bool operator() (State & a, State & b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> counter;
        for (string v: words) {
            counter[v] ++;
        }
        priority_queue<State, vector<State>, comparator> pq;
        for (auto & it: counter) {
            pq.push({it.second, it.first});
        }
        vector<string> res;
        for (int i = 0; i < k; i ++) {
            res.push_back(pq.top().second); pq.pop();
        }
        return res;
    }
};
