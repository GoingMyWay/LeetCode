class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int X1 = INT_MAX, Y1 = INT_MAX;
        int X2 = INT_MIN, Y2 = INT_MIN;
        using point = pair<int, int>;
        set<point> points;
        long recAreas = 0;
        for (auto & rec: rectangles) {
            int x1 = rec[0], y1 = rec[1];
            int x2 = rec[2], y2 = rec[3];
            X1 = min(x1, X1), Y1 = min(y1, Y1);
            X2 = max(x2, X2), Y2 = max(y2, Y2);
            recAreas += ((long)x2 - (long)x1) * ((long)y2 - (long)y1);
            
            for (point & p: vector<point>({{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}})) {
                if (points.find(p) != points.end()) {
                    points.erase(p);
                } else {
                    points.emplace(p);
                }
            }
        }

        if(points.size() != 4) return false;

        if (points.find({X1, Y1}) == points.end()) return false;
        if (points.find({X1, Y2}) == points.end()) return false;
        if (points.find({X2, Y1}) == points.end()) return false;
        if (points.find({X2, Y2}) == points.end()) return false;

        if (((long)X2 - (long)X1) * ((long)Y2 - (long)Y1) != recAreas) {
            return false;
        }

        return true;
    }
};