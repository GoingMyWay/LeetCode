class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

private:
    struct less_than_key {
        inline bool operator() (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), less_than_key());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i ++) {
            auto inter = intervals[i];
            auto last = res[res.size()-1];
            if (inter[0] <= last[1]) {
                res[res.size()-1][1] = max(inter[1], last[1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

};
