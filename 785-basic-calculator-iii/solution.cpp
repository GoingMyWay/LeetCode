class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (int i = 0; i < s.size(); i ++) {
            q.push(s[i]);
        }
        return cal(q);
    }

    int cal(queue<char> & q) {
        vector<int> res;
        char sign = '+';
        int num = 0;

        while (q.size() > 0) {
            char c = q.front(); q.pop();
            if (isdigit(c)) {
                num = 10 * num + (c-'0');
            }

            if (c == '(') {
                num = cal(q);
            }

            if ((!isdigit(c) && c != ' ') || q.size() == 0) {
                if (sign == '+') {
                    res.push_back(num);
                }
                if (sign == '-') {
                    res.push_back(-num);
                }
                if (sign == '*') {
                    res[res.size()-1] = num * res[res.size()-1];
                }
                if (sign == '/') {
                    res[res.size()-1] = res[res.size()-1] / num;
                }
                num = 0;
                sign = c;
            }

            if (c == ')') {
                break;
            }
        }
        int sumv = 0;
        for (auto v: res) {
            sumv += v;
        }
        return sumv;
    }
    
};