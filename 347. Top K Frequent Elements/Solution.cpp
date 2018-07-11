class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> valueCount;
        unordered_map<int, vector<int>>  freqVector;
        for (int & v : nums) valueCount[v] += 1;
        for (auto & p : valueCount) freqVector[p.second].push_back(p.first);
        
        vector<int> result;
        int maxFrequency = nums.size() - valueCount.size() + 1;
        
        while (maxFrequency > 0 && k > 0) {
            auto p = freqVector.find(maxFrequency);
            if (p != freqVector.end()) {
                int size = p->second.size();
                int numInserted = k < size ? k : size;
                result.insert(result.end(), p->second.begin(), p->second.begin()+numInserted);
                k -= numInserted;
                maxFrequency --;
            } else maxFrequency --;
        }
        return result;
    }
};

