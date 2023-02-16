class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        if (k == 0) return vector<int>{0};
        int currv = k;
        vector<int> res;
        int i = num.size() - 1, carry = 0;
        while (currv != 0 || i >= 0 || carry == 1) {
            int m = currv % 10;
            currv /= 10;
            int val = m + (i < 0 ? 0: num[i]) + carry;
            res.push_back(val % 10);
            carry = val / 10;
            i --;
        }
        if (carry != 0) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};
