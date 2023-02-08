class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++)
        {
            pair<map<int, int>::iterator, bool> ret = mp.insert(make_pair(nums[i], 1));
            if (!ret.second) //namely the nums[i] is already in the list
                ++ret.first->second;
        }
        map<int, int>::iterator iter = mp.begin();
        while (iter != mp.end())
        {
            if (iter->second > nums.size()/2)
                return iter->first;
            ++iter;
        }
    }
};