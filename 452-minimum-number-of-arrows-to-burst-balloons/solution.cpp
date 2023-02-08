bool sortBySec(const vector<int> &a,
               const vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        // sort(points.begin(), points.end(), sortBySec);
        sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });

        int count = 1;
        int x_end = points[0][1];
        for (auto point: points) {
            int start = point[0];
            if (start > x_end) {
                count ++;
                x_end = point[1];
            }
        }
        return count;
    }
};
