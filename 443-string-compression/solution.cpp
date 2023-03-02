class Solution {
public:
    int compress(vector<char>& chars) {
        int left = 0, right = 0;
        while (left < chars.size()) {
            int len = 0;
            while (left + len < chars.size() && chars[left + len] == chars[left]) {
                len ++;
            }
            chars[right++] = chars[left];
            if (len > 1) {
                for (char c : to_string(len)) {
                    chars[right++] = c;
                }
            }
            left += len;
        }
        return right;
    }
};
