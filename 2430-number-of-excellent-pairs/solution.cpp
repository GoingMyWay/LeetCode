class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> bits;
        for (auto x: s) bits.push_back(__builtin_popcount(x));

        sort(bits.begin(), bits.end());
        int n = bits.size(), j = n -1;
        long long ret = 0;
        for (int i = 0; i < n; i ++) {
            while ( j >= 0 && bits[i] + bits[j] >= k) j --;

            if (j >= i) ret += n - (j+1);
            else ret += n - (i+1);
        }
        ret *= 2;
        for (auto x: bits) {
            if (x*2 >= k) ret += 1;
        }
        return ret;
    }
};
