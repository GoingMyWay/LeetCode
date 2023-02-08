class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        for (auto c: s) counter[c] ++;
        using State = pair<int, char>;
        priority_queue<State, vector<State>, less<State>> pq;
        for (auto & it: counter) {
            char ch = it.first;
            int n = it.second;
            pq.push({n, ch});
        }

        string result = "";
        while (pq.size() > 0) {
            int count = pq.top().first;
            int ch = pq.top().second;
            for (int i = 0; i < count; i ++) {
                result += ch;
            }
            pq.pop();
        }
        return result;
    }
};
