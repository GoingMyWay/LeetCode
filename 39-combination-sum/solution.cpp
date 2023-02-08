class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        backTrack(candidates, 0, target, track);
        return res;
    }

    void backTrack(vector<int>& nums, int start, int target, vector<int>& track) {
        int sum = accumulate(track.begin(), track.end(), 0);
        if (sum == target) {
            res.push_back(track);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < nums.size(); i ++) {
            if (sum + nums[i] <= target) {
                track.push_back(nums[i]);
                backTrack(nums, i, target, track);
                track.pop_back();
            }
        }
    }
};
