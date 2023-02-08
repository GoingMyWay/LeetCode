class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        for (auto & v: nums) visited[v] = false;
        backTracking(track, nums);
        return res;
    }

    void backTracking(vector<int>& track, vector<int>& nums) {
        if (track.size() == nums.size()) {
            res.push_back(vector<int>(track.begin(), track.end()));
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (visited[i]) {
                continue;
            }
            track.push_back(nums[i]);
            visited[i] = true;
            backTracking(track, nums);
            track.pop_back();
            visited[i] = false;
        }
    }

private:
    unordered_map<int, bool> visited;
    vector<vector<int>> res;
};
