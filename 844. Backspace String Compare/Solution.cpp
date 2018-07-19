class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1, s2;
        for (auto & s: S) {
            if (s != '#') s1.push(s);
            else if (!s1.empty()) s1.pop();
        }
        for (auto & s: T) {
            if (s != '#') s2.push(s);
            else if (!s2.empty()) s2.pop();
        }
        if (s1.size() != s2.size()) return 0;
        while (!s1.empty() && !s2.empty()) {
            if (s1.top() != s2.top()) return 0;
            s1.pop(); s2.pop();
        }
        return 1;
    }
};

