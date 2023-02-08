class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> track;
        for (int i = 0; i < nums.size(); i++) { used.push_back(false); }
        backTrack(nums, track);
        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& track) {
        if (track.size() == nums.size()) { 
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            used[i] = true;
            track.push_back(nums[i]);
            backTrack(nums, track);
            track.pop_back();
            used[i] = false;
        }
    }
};
