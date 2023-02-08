class Solution {
public:
    bool isValid(string s) {
        stack<char> h;
        for (int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') {
                h.push(c);
            } else {
                if (h.size() > 0) {
                    char leftOfc = leftOf(c);
                    char popOut = h.top(); h.pop();
                    if (popOut != leftOfc) return false;
                } else {
                    return false;
                }
            }
        }
        return h.size() == 0;
    }

    char leftOf(char c) {
        if (c == ']') return '[';
        if (c == ')') return '(';
        return '{';
    }
};