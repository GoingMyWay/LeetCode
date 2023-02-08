class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow ++;
                nums[slow] = nums[fast];
            }
            fast ++;
        }
        return slow + 1;
    }
};