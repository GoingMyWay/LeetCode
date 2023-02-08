class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int w1 = -1, w2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i ++) {
            if (wordsDict[i] == word1) {
                w1 = i;
            }
            if (wordsDict[i] == word2) {
                w2 = i;
            }
            if (w1 != -1 && w2 != -1) {
                res = min(res, abs(w1-w2));
            }
        }
        return res;
    }
};