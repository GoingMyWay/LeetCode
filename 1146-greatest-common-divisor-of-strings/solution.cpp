class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(), len2 = str2.length();
        string base = len1 > len2 ? str2 : str1;
        string res;
        for (int i = base.size() - 1; i >= 0; i --) {
            if (!isGCD(base, str1) || !isGCD(base, str2)) {
                base = base.substr(0, base.size()-1);
            } else {
                return res.size() < base.size() ? base : res;
            }
        }
        return res;
    }

private:
    bool isGCD(string& base, string& str) {
        if (str.size() % base.size() == 0) {
            int chunk = str.size() / base.size();
            return joinKBase(base, chunk) == str;
        }
        return false;
    }

    string joinKBase(string& base, int k) {
        string res(base);
        for (int i = k - 1; i > 0; i --) {
            res += base;
        }
        return res;
    }
};