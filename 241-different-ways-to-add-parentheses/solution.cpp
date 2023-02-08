class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        vector<int> res;
        for (int i = 0; i < expression.size(); i ++) {
            char c = expression[i];
            if (c == '-' || c == '*' || c == '+') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right= diffWaysToCompute(expression.substr(i+1));
                for (int a: left) {
                    for (int b: right) {
                        if (c == '+') {
                            res.push_back(a + b);
                        } else if (c == '-') {
                            res.push_back(a - b);
                        } else if (c == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        if (res.size() == 0) {
            res.push_back(stoi(expression));
        }
        memo[expression] = res;
        return res;
    }

private:
    unordered_map<string, vector<int>> memo;
};