class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string res;
        int m = a.size(), n = b.size();
        int carry = 0, i = 0;

        while (i < max(m, n) || carry > 0) {
            int val = carry;
            val += i < m ? (a[i] - '0') : 0;
            val += i < n ? (b[i] - '0') : 0;
            res += to_string(val % 2);
            carry = val / 2;
            i ++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
