class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxv = *max_element(nums.begin(), nums.end());
        int minv = *min_element(nums.begin(), nums.end());
        return max(0, maxv-k-minv-k);
    }
};