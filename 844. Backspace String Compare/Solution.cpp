class Solution {
public:
    bool backspaceCompare2(string S, string T) {
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

    bool backspaceCompare(string S, string T) {
        string r1 = stringBuilder(S);
        string r2 = stringBuilder(T);
        if (r1.size() != r2.size()) return false;
        for (int j = 0; j < r1.size(); j ++) {
            if (r1[j] != r2[j]) return false;
        }
        return true;
    }
    
    string stringBuilder(string inputStr) {
        int j = inputStr.size(), skip = 0;
        string res = "";
        while (j >= 0) {
            if (inputStr[j] == '#') skip ++;
            else if (skip != 0) skip --;
            else res += inputStr[j];
            j --;
        }
        return res;
    }
};

