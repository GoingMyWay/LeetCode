class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            moves += nums[i] - nums[0];
        }
        return moves;
        // int sumv = accumulate(nums.begin(), nums.end(), 0);
        // int minv = *min_element(nums.begin(), nums.end());
        // return sumv - minv * nums.size();
    }
};
