class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size(), col = strs[0].size();
        int res = 0;
        for (int j = 0; j < col; j ++) {
            for (int i = 1; i < row; i ++) {
                if (strs[i][j] - strs[i-1][j] < 0) {
                    res ++;
                    break;
                }
            }
        }
        return res;
    }
};
