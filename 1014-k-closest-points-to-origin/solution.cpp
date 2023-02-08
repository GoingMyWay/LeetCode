double euclidean(const vector<int>& a) {
    return (double)(a[0]*a[0] + a[1]*a[1]);
}

class Solution {
public:
    struct comp {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return euclidean(a) < euclidean(b);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for (auto & v: points) {
            pq.push(v);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (pq.size() > 0) {
            res.push_back(pq.top()); pq.pop();
        }
        return res;
    }
};
