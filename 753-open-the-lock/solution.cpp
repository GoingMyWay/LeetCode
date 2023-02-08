class Solution {
public:
    string plusOne(string s, int j) {
        if (s[j] == '9') {
            s[j] = '0';
        } else {
            s[j] += 1;
        }
        return s;
    }

    string minusOne(string s, int j) {
        if (s[j] == '0') {
            s[j] = '9';
        } else {
            s[j] -= 1;
        }
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        set<string> deads;
        for (auto &s: deadends) deads.insert(s);
        set<string> visited;
        queue<string> q;
        int step = 0;
        q.push("0000");
        visited.insert("0000");

        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string cur = q.front(); q.pop();

                if (deads.count(cur) == 1) {
                    continue;
                }
                if (cur == target) {
                    return step;
                }
                for (int j = 0; j < 4; j ++) {
                    string up = plusOne(cur, j);
                    if (visited.count(up) == 0) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if (visited.count(down) == 0) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};