class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (f(nums, mid) > k)
                left = mid + 1;
            else if (f(nums, mid) < k)
                right = mid - 1;
            else if (f(nums, mid) == k)
                right = mid - 1;
        }
        return left;
    }

    int f(vector<int>& nums, int candidate) {
        int i = 0, k = 0;
        while (i < nums.size()) {
            int cap = candidate;
            while (i < nums.size()) {
                if (cap < nums[i])
                    break;
                else
                    cap -= nums[i];
                i ++;
            }
            k ++;
        }
        return k;
    }
};
