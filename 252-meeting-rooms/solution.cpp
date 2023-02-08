class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i ++) {
            if (i + 1 < intervals.size() && intervals[i+1][0] < intervals[i][1]) {
                return false;
            }
        }
        return true;
    }
};