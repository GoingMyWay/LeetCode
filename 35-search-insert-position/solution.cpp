class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return leftBound(nums, target);      
    }

    int leftBound(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }
        return left;
    }
};