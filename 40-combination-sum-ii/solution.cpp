class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backTrack(candidates, 0, target, track);
        return res;
    }

    void backTrack(vector<int>& nums, int start, int target, vector<int>& track) {
        if (accumulate(track.begin(), track.end(), 0) == target) {
            res.push_back(track);
            return;
        }

        for (int i = start; i < nums.size(); i ++) {
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            int sum = accumulate(track.begin(), track.end(), 0);
            if (sum + nums[i] <= target) {
                track.push_back(nums[i]);
                backTrack(nums, i + 1, target, track);
                track.pop_back();
            }
        }
    }
};