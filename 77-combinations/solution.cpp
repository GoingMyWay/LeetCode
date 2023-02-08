class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backTrack(n, k, 1, track);
        return res;
    }

    void backTrack(int n, int k, int start, vector<int>& track) {
        if (track.size() == k) {
            res.push_back(track);
        }
        for (int i = start; i <= n; i ++) {
            track.push_back(i);
            backTrack(n, k, i+1, track);
            track.pop_back();
        }
    }
};
