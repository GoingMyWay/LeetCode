class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backTrack(nums, 0, track);
        return res;
    }

    void backTrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i ++) {
            track.push_back(nums[i]);
            backTrack(nums, i+1, track);
            track.pop_back();
        }
    }
};