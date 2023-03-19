class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int WIDTH = 2 * nums[nums.size() - 1];
        
        //multiplicity[i] = number of nums[j] == nums[i] (j < i)
        vector<int> multiplicity(nums.size());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                multiplicity[i] = 1 + multiplicity[i - 1];
            }
        }

        //prefix[v] = number of values <= v
        vector<int> prefix(WIDTH);
        int left = 0;
        for (int i = 0; i < WIDTH; ++i) {
            while (left < nums.size() && nums[left] == i)
                left++;
            prefix[i] = left;
        }

        int lo = 0, hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                count += prefix[nums[i] + mi] - prefix[nums[i]] + multiplicity[i];
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
};
