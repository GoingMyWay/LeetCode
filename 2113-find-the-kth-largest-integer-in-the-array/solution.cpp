class Solution {
public:
    struct comp {
        bool operator() (const string& a, const string& b) {
            return (a.size() != b.size()) ? (a.size() > b.size()) : (a > b);
        }
    };

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comp> pq;
        for (auto & v: nums) {
            pq.push(v);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

