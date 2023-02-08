class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res; res.push_back(-1); res.push_back(-1);
        int dup = -1, missing = 1;
        for (int n : nums) {
            if (nums[abs(n)-1] < 0) dup = abs(n);
            else nums[abs(n)-1] *= -1;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        res[0] = dup; res[1] = missing;
        return res;
    }
};
