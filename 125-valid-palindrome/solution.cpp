class Solution {
public:
    bool isPalindrome(string s) {
        string newS = "";
        for (auto v: s) { 
            if ((( v >= 'a' && v <= 'z') || ( v >= 'A' && v <= 'Z')) || (v >= '0' && v <= '9')) { 
                newS += v;
            }
        }
        transform(newS.begin(), newS.end(), newS.begin(), ::toupper);
        int l = 0, r = newS.size()-1;
        while ( l < r ) {
            if (newS[l] == newS[r]) {
                l ++;
                r --;
            } else return false;
        }
        return true;
    }
};