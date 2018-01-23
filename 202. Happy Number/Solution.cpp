class Solution {
public:
    bool isHappy(int n) {
        map<int, int> hashMap;
        map<int, int>::iterator iter;
        int sum = 0;
        while (1) {
            while ( n != 0 ) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
            if ( 1 == n ) { return 1; }
            iter = hashMap.find(n);
            if ( iter == hashMap.end() ) { hashMap.insert(pair<int, int>(n, 1)); }
            else return 0;
            sum = 0;
        }
    }
};
