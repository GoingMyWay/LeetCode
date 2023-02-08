class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int countLine = 1, width = 0;
        for (auto & s : S) {
            if (width + widths[s-'a'] <= 100) width += widths[s-'a'];
            else {
                countLine += 1;
                width = widths[s-'a'];
            }
        }
        vector<int> result = {countLine, width};
        return result;
    }
};
