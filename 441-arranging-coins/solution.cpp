class Solution {
public:
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while (left <= right) {
            long long int k = left + (right - left) / 2;
            long long int curr = k * (k + 1) / 2; // calculate the result
            if (curr == n) return k;  // return the right result
            if (curr < n) left = k + 1; 
            else right = k - 1;
        }
        return right;
    }
};
