class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        typedef bitset<20> bs20;
        if (k > nums.size())return false;
        int sum = 0;
        for (int i: nums)sum += i;
        if (sum % k)return false;
        int target = sum / k;
        //最大的数比target大
        if(nums[0]>target)return false;
        unordered_set<bs20> memo;
        sort(nums.begin(), nums.end(), greater<int>());

        function<bool(int, int, bs20)> backtrack = [&](int at, int sum, bs20 used) {
            if (memo.count(used))return false;
            if (at == k) {
                return true;
            }
            if (sum == target) {
                return backtrack(at + 1, 0, used);
            } else {
                for (int i = 0; i < nums.size(); i++) {
                    if (used[i])continue;
                    if (sum + nums[i] > target)continue;
                    sum += nums[i];
                    used[i] = 1;
                    if (backtrack(at, sum, used)) {
                        return true;
                    } else {
                        //记录失败情况
                        memo.insert(used);
                    }
                    sum -= nums[i];
                    used[i] = 0;
                    //没有能够凑成target
                    if(sum==0)break;
                }
            }
            return false;
        };
        
        return backtrack(0, 0, 0);
    }
};