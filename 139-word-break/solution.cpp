class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        set<int> setLen;
        for (auto w : wordDict) setLen.insert(w.size());
        
        lengthList = vector<int>(setLen.begin(), setLen.end());
        memo = vector<bool>(s.size()+1, false);
        dfs(s, 0, wordSet);
        return res;
    }

private:
    bool res = false;
    vector<bool> memo;
    vector<int> lengthList;
    void dfs(string& s, int start, set<string>& wordSet) {
        if (memo[start]) return;
        if (start >= s.size()) {
            res = true;
            return;
        }
        for (int i = 0; i < lengthList.size() && lengthList[i] <= s.size() - start; i ++) {
            string subStr = s.substr(start, lengthList[i]);
            if (wordSet.find(subStr) != wordSet.end()) {
                dfs(s, start+lengthList[i], wordSet);
                memo[start+lengthList[i]] = true;
                if (res) break;
            }
        }
    }
};