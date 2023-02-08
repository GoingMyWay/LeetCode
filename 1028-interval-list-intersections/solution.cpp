class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < firstList.size() && j < secondList.size()) {
            auto a = firstList[i], b = secondList[j];
            if (b[0] <= a[1] && a[0] <= b[1]) {
                res.push_back({max(a[0], b[0]), min(a[1], b[1])});
            }
            if (a[1] > b[1]) {
                j ++;
            } else {
                i ++;
            }
        }
        return res;
    }
};
