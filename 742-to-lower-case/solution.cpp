class Solution {
public:
    string toLowerCase(string str) {
        string result = "";
        for (auto & s : str) {
            if (s >= 'A' && s <= 'Z') s = s - 'A' + 'a';
        }
        return str;
    }
};