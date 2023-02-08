class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) return 1;

        int result = 2;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> cnt;
            for (int j = 0; j < n; j++) {
                if (j != i) cnt[calSlope(points[i], points[j])] += 1;
            }
            for (auto const & [h, count] : cnt) {
                result = max(result, count + 1);
            }
        }
        return result;
    }

    double calSlope(vector<int>& p1, vector<int>& p2) {
        int x1 = p1[0], x2 = p2[0];
        int y1 = p1[1], y2 = p2[1];
        
        if (x1 == x2) return DBL_MAX;
        if (y1 == y2) return 0;
        return (double) (y2 - y1) / (double) (x2 - x1);
    }
};
