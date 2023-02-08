class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        string track;
        backtrack(digits, 0, track);
        return res;
    }

    void backtrack(string& digits, int start, string& track) {
        if (track.size() == digits.size()) {
            res.push_back(track);
            return;
        }
        for (char c: mapping[digits[start]-'0']) {
            track.push_back(c);
            backtrack(digits, start+1, track);
            track.pop_back();
        }
    }

private:
    vector<string> res;
    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
};
