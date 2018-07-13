class Solution {
public:
    string toLowerCase(string str) {
        string result = "";
        for (auto s : str) {
            if (s >= 'A' && s <= 'Z') {
                result += 'a' + s - 'A';
            } else result += s;
        }
        return result;
    }
};

