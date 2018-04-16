#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addingPar(result, "", n, n, n);
        return result;
    }
    void addingPar(vector<string> &v, string str, int n, int left, int right){
        if ( left==0 && right==0 ) {
            v.push_back(str);
            return;
        }
        
        if ( left > 0 ) { addingPar(v, str+"(", n, left-1, right); }
        if ( n-left > n-right ) { addingPar(v, str+")", n, left, right-1); }
    }
};
