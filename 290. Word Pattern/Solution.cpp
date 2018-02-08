class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> pIndexMap;
        map<string, int> wIndexMap;
        istringstream in(str);
        int i = 0, n = pattern.size();
        string word;
        while (in >> word) {
            if (i == n || pIndexMap[pattern[i]] != wIndexMap[word])
                return false;
            pIndexMap[pattern[i]] = wIndexMap[word] = i + 1;
            i ++;
        }
        return i == n;
    }
};

