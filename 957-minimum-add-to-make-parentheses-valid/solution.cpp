class Solution {
public:
    int minAddToMakeValid(string s) {
        int need = 0, res = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (s[i] == '(') {
                need ++;
            }
            if (s[i] == ')') {
                need --;
                if (need == -1) {
                    need = 0;
                    res ++;
                }
            }
        }
        return res + need;
    }
};