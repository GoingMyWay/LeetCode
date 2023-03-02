class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i ++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        auto iter = projects.begin();
        priority_queue<int> q;
        for (int i = 0; i < k; i ++) {
            while (iter != projects.end() && iter->first <= w) {
                q.push(iter->second);
                iter ++;
            }
            if (q.size() == 0) break;
            w += q.top();
            q.pop();
        }
        return w;
    }
};
