class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>::iterator iter;
        map<char, int> hashMap;
        for ( auto ch:s ) {
            iter = hashMap.find(ch);
            if ( iter == hashMap.end() ) {
                hashMap.insert(pair<char, int>(ch, 1));
            } else {
                hashMap[ch] += 1;
            }
        }
        
        int hasOdd = 0, res = 0;
        iter = hashMap.begin();
        while ( iter != hashMap.end() ) {
            if ( iter->second % 2 == 0 ) { res += iter->second; }
            else { 
                res += iter->second - 1;
                hasOdd = 1;
            }
            iter ++;
        }
        return res + ( hasOdd ? 1 : 0 );
    }
};
