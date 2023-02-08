class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        vector<int> arr(v.size());
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&v](int i1, int i2) {return v[i1] == v[i2] ? i1 < i2 : v[i1] < v[i2]; });

        for (auto i = 0, max_i = 0, ch = 0; i <= arr.size(); ++i) {
          if (i == arr.size()) return ch;
          max_i = max(max_i, arr[i]);
          if (max_i == i) ++ch;
        }
    }
};