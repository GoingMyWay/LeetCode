class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        for (auto v : A) {
            if (v % 2 == 0) res.insert(res.begin(), v);
            else res.emplace_back(v);
        }
        return res;
    }
};