class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0, s = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i ++) {
            if (lSum == s - lSum - nums[i]) return i;
            lSum += nums[i];
        }
        return -1;
    }
};
