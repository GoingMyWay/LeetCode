class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n+1);
        unordered_map<int, int> m;
        preSum[0] =  0;
        m[0] = 1;
        int res = 0;
        for (int i = 0; i < n; i ++) {
            preSum[i+1] = preSum[i] + nums[i];
            int curRemainder = preSum[i+1] % k;
            if (curRemainder < 0) {
                curRemainder += k;
            }
            if (m.count(curRemainder)) {
                int count = m[curRemainder];
                res += count;
                m[curRemainder] = count + 1;
            } else {
                m[curRemainder] = 1;
            }
        }
        return res;
    }
};
