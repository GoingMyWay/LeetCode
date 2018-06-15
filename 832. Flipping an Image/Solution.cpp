
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto & vec : A) reverse(vec.begin(), vec.end());
        for (auto & vec : A) {
            for (int & v : vec) v ^= 1;
        }
        return A;
    }
};

