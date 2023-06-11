class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int s : stones) q.push(s);
        while (q.size() > 0) {
            if (q.size() == 1) return q.top();
            if (q.size() >= 2) {
                int y = q.top(); q.pop();
                int x = q.top(); q.pop();
                if (y != x) q.push(y - x);
            }
        }
        return 0;
    }
};
