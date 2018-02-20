class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, next = 2;
        for ( int i = 3; i <= n; i ++ ) {
            int temp = next;
            next += pre;
            pre = temp;
        }
        return 1 == n ? n : next;
    }
}; 
