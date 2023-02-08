class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        using node = pair<int, pair<int, int>>;
        priority_queue<node, vector<node>, greater<node>> pq;
        for (int i = 0; i < matrix.size(); i ++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int res;
        while (pq.size() > 0 && k > 0) {
            node n = pq.top(); pq.pop();
            k --;
            res = n.first;
            int i = n.second.first, j = n.second.second;
            if (j + 1 < matrix[0].size()) {
                pq.push({matrix[i][j+1], {i, j+1}});
            }
        }
        return res;
    }
};
