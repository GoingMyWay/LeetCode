class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, 0, path, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>> & result) {
        result.push_back(path);
        for (int i=index; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            dfs(nums, i+1, path, result);
            path.pop_back();
        }
    }
};