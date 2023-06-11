class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for (auto v : nums) res *= v > 0 ? 1 : (v == 0 ? 0 : -1);
        return res > 0 ? 1 : (res == 0 ? 0 : -1);
    }
};
