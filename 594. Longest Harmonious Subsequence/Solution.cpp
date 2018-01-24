class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        map<int, int> hashMap;
        map<int, int>::iterator iter;
        int max_len = 0;
        for (auto v: nums) {
            iter = hashMap.find(v);
            if (iter == hashMap.end()) {
                hashMap.insert(pair<int, int>(v, 1));
            } else {
                hashMap[v] += 1;
            }
        }
        for (auto v: nums) {
            iter = hashMap.find(v+1);
            if (iter != hashMap.end()) {
                if (hashMap[v]+hashMap[v+1] > max_len) {
                    max_len = hashMap[v] + hashMap[v+1];
                }
            }
        }
        return max_len;
    }
};
