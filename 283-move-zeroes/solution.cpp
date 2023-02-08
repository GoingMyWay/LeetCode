class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = removeZero(nums, 0);
        for (int i = index; i < nums.size(); i ++) {
            nums[i] = 0;
        }
    }
    int removeZero(vector<int>& nums, int val) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow ++;
            }
            fast ++;
        }
        return slow;
    }
};