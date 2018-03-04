class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for ( auto v: s ) result = result * 26 +  v - A + 1 ;
        return result;
    }
};
