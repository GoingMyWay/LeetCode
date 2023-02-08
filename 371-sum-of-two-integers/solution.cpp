class Solution {
public:
    int getSum(int x, int y)
    {
        if ( 0 == y ) return x;
 
        int sum = x ^ y;
        int carry = (x & y) << 1;
        return getSum(sum, carry);
    }
};