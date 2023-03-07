class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int leftBound = -1, minIndex = -1, maxIndex = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;
            if (nums[i] == minK) minIndex = i;
            if (nums[i] == maxK) maxIndex = i;
            res += max(0, min(minIndex, maxIndex) - leftBound);
        }
        return res;
    }
};
