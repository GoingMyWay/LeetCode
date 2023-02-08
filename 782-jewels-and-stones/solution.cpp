class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        set<char> iset;
        for (char v: J) {
            iset.insert(v);
        }
        set<char>::iterator iter;
        for (char v: S) {
            if ( iset.find(v) != iset.end() ) count ++;
        }
        return count;
    }
};