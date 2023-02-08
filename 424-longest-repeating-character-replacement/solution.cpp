class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> windowCharCount(26, 0);
        int windowMaxCount = 0;
        int res = 0;

        while (right < s.length()) {
            windowCharCount[s[right]-'A'] ++;
            windowMaxCount = max(windowMaxCount, windowCharCount[s[right]-'A']);
            right ++;

            while (right - left - windowMaxCount > k) {
                windowCharCount[s[left]-'A'] --;
                left ++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};