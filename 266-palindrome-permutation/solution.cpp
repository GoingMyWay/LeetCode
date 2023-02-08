class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count = 0;
        for (int i = 0; i < 128 && count <= 1; i++) {
            int ct = 0;
            for (int j = 0; j < s.size(); j++) {
                if (s[j]-'0' == i)
                    ct++;
            }
            count += ct % 2;
        }
        return count <= 1;
    }
};
