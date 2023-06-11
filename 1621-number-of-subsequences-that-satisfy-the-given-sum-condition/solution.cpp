class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        const unsigned int mod = 1000000007;
        sort(nums.begin(), nums.end());
        
        // Precompute the value of 2 to the power of each value.
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        int answer = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer += power[right - left];
                answer %= mod;
                left++;
            } else {
                right--;
            }
        }
        
        return answer;
    }
};