class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, res = nums.size();
        int sumv = 0;
        bool found = false;

        while (right < nums.size()) {
            int v = nums[right];
            sumv += v;
            right ++;

            if (sumv >= target) {
                res = min(res, right - left);
                found = true;
            }
            while (sumv >= target) {
                int p = nums[left];
                left ++;
                if (sumv - p >= target) {
                    res = min(res, right - left);
                }
                sumv -= p;
            }
        }
        return found ? res: 0;
    }
};
