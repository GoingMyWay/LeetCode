
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int max_len = 0;
        for (auto v: nums) { hashMap[v] ++; }
        for (auto v: nums) {
            if (hashMap.find(v+1) != hashMap.end()) { max_len = max(max_len, hashMap[v]+hashMap[v+1]); }
        }
        return max_len;
    }
};

