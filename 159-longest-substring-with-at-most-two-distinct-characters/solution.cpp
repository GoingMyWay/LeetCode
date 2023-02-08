class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right ++) {
            m[s[right]] ++;

            while (m.size() > 2) {
                m[s[left]] --;
                if (m[s[left]] == 0) {
                    m.erase(s[left]);
                }
                left ++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
