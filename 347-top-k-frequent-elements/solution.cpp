class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int v: nums) {
            counter[v] ++;
        }
        using State = pair<int, int>;
        priority_queue<State, vector<State>, less<State>> pq;
        for (auto & it: counter) {
            pq.push({it.second, it.first});
        }
        vector<int> res;
        for (int i = 0; i < k; i ++) {
            res.push_back(pq.top().second); pq.pop();
        }
        return res;
    }
};
