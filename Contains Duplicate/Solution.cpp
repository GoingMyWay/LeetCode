class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        map<int, int> Map;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++)
        {
            pair<map<int, int>::iterator, bool> ret = 
                Map.insert(make_pair(nums[i], 1));
            if (!ret.second) //namely the nums[i] is already in the list
                return 1;
        }
        return 0;
    }
};