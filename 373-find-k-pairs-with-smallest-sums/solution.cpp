class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;

        for (int x: nums1) {
            for (int y: nums2) {
                int sum = x + y;
                if (pq.size() < k) {
                    pq.push({sum, {x, y}});
                } else if (sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {x, y}});
                } else {
                    break;
                }
            }
        }
        
        vector<vector<int>> res;
        while (pq.size() > 0) {
            auto v = pq.top(); pq.pop();
            res.push_back({v.second.first, v.second.second});
        }
        return res;
    }
};
