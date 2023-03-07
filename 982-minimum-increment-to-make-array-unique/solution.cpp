class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxVal = 0;
        for (int x : nums) {
            maxVal = max(maxVal, x);
        }
        
        vector<int> count(nums.size() + maxVal);
        for (int x : nums) {
            count[x]++;
        }

        int moves = 0, taken = 0;
        for (int x = 0; x < nums.size() + maxVal; ++x) {
            if (count[x] > 1) {
                taken += count[x] - 1;
                moves -= x * (count[x] - 1);
            } else if (taken > 0 && count[x] == 0) {
                taken --;
                moves += x;
            }
        }
        return moves;
    }
};
