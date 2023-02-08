class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int start) {
        if (track.size() >= 2) {
            res.push_back(track);
        }
        set<int> visited;
        for (int i = start; i < nums.size(); i ++) {
            if (track.size() > 0 && track.back() > nums[i]) {
                continue;
            }
            if (visited.count(nums[i])) {
                continue;
            }
            track.push_back(nums[i]);
            visited.insert(nums[i]);
            backtrack(nums, i + 1);
            track.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> track;
};
