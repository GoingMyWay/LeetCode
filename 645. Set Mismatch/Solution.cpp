class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i ++) { hashMap[i+1] = 0; }
        for (auto v: nums) { hashMap[v] ++; }
        
        vector<int> res; res.push_back(-1); res.push_back(-1);
        
        for (auto& p: hashMap) {
            if (p.second == 2) { res[0] = p.first; }
            if (p.second == 0) { res[1] = p.first; }
        }
        return res;
    }
};
