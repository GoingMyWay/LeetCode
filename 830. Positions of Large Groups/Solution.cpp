class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int l = 0, r = 0;
        while (1) {
            if (S[l] == S[r]) {
                r ++;
                if (r == S.size() && r - l >= 3) {
                    vector<int> _res; 
                    _res.push_back(l);
                    _res.push_back(r-1);
                    result.push_back(_res);
                    break;
                }
            } else {
                if (r - l >= 3) {
                    vector<int> _res; 
                    _res.push_back(l);
                    _res.push_back(r-1);
                    result.push_back(_res);
                }
                l = r;
            }
            if (r == S.size()) break;
        }
        return result;
    }
};

