class Solution {
public:
    struct less_than_key {
        inline bool operator() (const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }
    };

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less_than_key());

        int left = intervals[0][0];
        int right = intervals[0][1];

        int res = 0;
        for (int i = 1; i < intervals.size(); i++) {
            auto inter = intervals[i];
            // inter is in the current interval
            if (inter[0] >= left && inter[1] <= right) {
                res ++;
            }
            // inter overlaps with the current interval
            if (inter[0] <= right && inter[1] > right) {
                right = inter[1];
            }
            // no overlap
            if (inter[0] > right) {
                left = inter[0];
                right = inter[1];
            }
        }
        return intervals.size() - res;
    }
};