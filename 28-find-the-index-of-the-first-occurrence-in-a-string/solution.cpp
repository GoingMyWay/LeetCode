class Solution {
public:
    int strStr(string haystack, string needle) {
        int right = 0;
        for (int i = 0; i < haystack.size(); i ++) {
            int len = 0, right = i;
            while (len < needle.size() && right < haystack.size() && 
                   haystack[right] == needle[len]) {
                       right ++;
                       len ++;
            }
            if (len == needle.size()) return i;
        }
        return -1;
    }
};
