class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return unique(begin(nums), end(nums)) != end(nums);
    }
};