class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addParan(res, "", n, 0);
        return res;
    }
    void addParan(vector<string> &res, string s, int n, int m) {
        if (n ==0 && m == 0) {
            res.push_back(s);
            return;
        }
        if ( m > 0 ) { addParan(res, s+")", n, m-1); }
        if ( n > 0 ) { addParan(res, s+"(", n-1, m+1); }
    }
};