class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        for (auto i = 0, max_i = 0, chk = 0; i <= arr.size(); ++i) {
          if (i == arr.size()) return chk;
          max_i = max(max_i, arr[i]);
          if (max_i == i) ++chk;
        }
    }
};