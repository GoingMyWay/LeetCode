class Solution {
public:
    bool rotateString(string A, string B) {
        for ( int step = 0; step < A.size(); ++ step ) {
            bool is_ok = true;
            for ( int i = 0; i < A.size(); ++ i ) {
                if ( A[(i+step) % A.size() ] != B[i] ) {
                    is_ok = false;
                    break;
                }
            }
            if ( is_ok ) return true;
        }
        return false;
    }
};
