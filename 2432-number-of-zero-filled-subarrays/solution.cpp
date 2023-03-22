class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0;
        long long res = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                int r = i + 1;
                while (r < nums.size()) {
                    if (nums[r] == 0) r ++;
                    else break;
                }
                res += (1 + (long long)(r - i)) * (long long)(r - i) / 2;
                i = r;
            } else i ++;
        }
        return res;
    }
};