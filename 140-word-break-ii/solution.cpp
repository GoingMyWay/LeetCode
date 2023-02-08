class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        set<string> outRes;
        set<string> wordset(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= s.size(); i ++) {
            string subStr = s.substr(0, i);
            vector<string> resStr;
            if (wordset.find(subStr) != wordset.end()) {
                resStr.push_back(subStr);
                backtrack(s.substr(i), resStr, wordset, outRes, i);
                resStr.pop_back();
            }
        }
        return vector<string>(outRes.begin(), outRes.end());
    }

private:
    int n = 0;
    void backtrack(string s, vector<string> & resStr, set<string> & wordset, set<string>& outRes, int accumLen) {
        for (int i = 1; i <= s.size(); i ++) {
            string subStr = s.substr(0, i);
            if (wordset.find(subStr) != wordset.end()) {
                resStr.push_back(subStr);
                backtrack(s.substr(i), resStr, wordset, outRes, accumLen+i);
                resStr.pop_back();
            }
        }
        if (accumLen == n) {
            string res;
            for (int i = 0; i < resStr.size(); i ++) {
                res += (i != resStr.size() - 1) ? resStr[i] +  " " : resStr[i];
            }
            outRes.insert(res);
        }
    }
};
