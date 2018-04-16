class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1) return s;
    string res[numRows];
    int i = 0, j, gap = numRows-2;
    while(i < s.size()){
        for(j = 0; i < s.size() && j < numRows; ++j) res[j] += s[i++];
        for(j = gap; i < s.size() && j > 0; --j) res[j] += s[i++];
    }
    string str = "";
    for(i = 0; i < numRows; ++i)
        str += res[i];
    return str;
    }
};