class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1(nums1.begin(), nums1.end());
        set<int> n2(nums2.begin(), nums2.end());
        vector<set<int>> res(2);
        for (auto v: nums1) if (n2.find(v) == n2.end()) res[0].insert(v);
        for (auto v: nums2) if (n1.find(v) == n1.end()) res[1].insert(v);
        
        return {vector<int>(res[0].begin(), res[0].end()), 
                vector<int>(res[1].begin(), res[1].end())};
    }
};