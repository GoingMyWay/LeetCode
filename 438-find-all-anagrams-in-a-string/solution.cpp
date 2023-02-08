class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (auto c: p) need[c] ++;
        int left = 0, right = 0, valid = 0;
        vector<int> res;

        while (right < s.size()) {
            char c = s[right];
            right ++;
            if (need.count(c)) {
                window[c] ++;
                if (need[c] == window[c]) {
                    valid ++;
                }
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                char d = s[left];
                left ++;
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid --;
                    }
                    window[d] --;
                }
            }
        }
        return res;
    }
};