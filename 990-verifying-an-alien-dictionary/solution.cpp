class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> indexMap;
        for (int i = 0; i < order.size(); i ++) {
            indexMap[order[i]] = i + 1;
        }
        for (int i = 1; i < words.size(); i ++) {
            if (!compare(words[i], words[i-1], indexMap)) {
                return false;
            }
        }
        return true;
    }

private:
    bool compare(string& w1, string& w2, unordered_map<char, int>& indexMap) {
        if (w1[0] != w2[0]) return indexMap[w1[0]] > indexMap[w2[0]];
        int i = 0, j = 0;
        while (i < w1.size() && j < w2.size()) {
            if (w1[i] == w2[j]) {
                i ++;
                j ++;
            } else if (indexMap[w1[i]] > indexMap[w2[i]]) {
                return true;
            } else {
                return false;
            }
    
            if (i == w1.size()) {
                if (j < w2.size()) return false;
                else return true;
            }
            if (j == w2.size()) {
                if (i < w1.size()) return true;
                else return false;
            }
        }
        return true;
    }
};