class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size()-1;
        set<char> m;
        m.insert('A');
        m.insert('E');
        m.insert('I');
        m.insert('O');
        m.insert('U');
        m.insert('a');
        m.insert('e');
        m.insert('i');
        m.insert('o');
        m.insert('u');
        while (l < r) {
            if (m.find(s[l]) != m.end() && m.find(s[r]) != m.end()) {
                char temp = s[l];
                s[l] = s[r];
                s[r] = temp;
                l ++;
                r --;
            } else if (m.find(s[l]) != m.end()) { 
                r --; 
            } else if (m.find(s[r]) != m.end()) {
                l ++;
            } else { l ++; r --; }
        }
        return s;
    }
};