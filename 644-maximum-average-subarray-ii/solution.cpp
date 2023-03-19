class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = nums[0], right = nums[0];
        for (int n: nums) {
            right = max(right, (double)n);
            left = min(left, (double)n);
        }
        while (right - left > 0.00001) {
            double mid = left + (right - left) / 2;
            if (check(nums, mid, k))
                left = mid;
            else
                right = mid;
        }
        return left;
    }

private:
    bool check(vector<int>& nums, double mid, int k) {
        double sum = 0, prevSum = 0, minSum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i] - mid;
            if (i >= k - 1) {
                if (sum - minSum >= 0) // greedy method
                    return true;
                prevSum += nums[i - k + 1] - mid;
                minSum = min(prevSum, minSum); // get the least accumulated sum
            }
        }
        return false;
    }
};