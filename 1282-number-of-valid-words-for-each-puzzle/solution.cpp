class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int> maskMap;
        for (string word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= 1 << (c - 'a');
            }
            ++maskMap[mask];
        }
        for (string puzzle : puzzles) {
            int mask = 0;
            for (char c : puzzle) {
                mask |= 1 << (c - 'a');
            }
            int sub = mask, cnt = 0, first = 1 << (puzzle[0] - 'a');
            while (true) {
                if ((sub & first) == first && maskMap.count(sub)) {
                    cnt += maskMap[sub];
                }
                if (sub == 0) break;
                sub = (sub - 1) & mask;
            }
            res.push_back(cnt);
        }
        return res;
    }
};