class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int v: nums) {
            pq.push(v);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
