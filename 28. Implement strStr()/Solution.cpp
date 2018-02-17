class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (0 == n) return 0;
        if (n > m) return -1;
        int i = 0, j = 0;
        for ( ; i <= m-n; i ++ ) {
            for ( j = 0; j < n; j ++ ) { if ( haystack[i+j] != needle[j] ) break; }
            if ( j == n ) return i;
        }
        return -1;
    }
};
