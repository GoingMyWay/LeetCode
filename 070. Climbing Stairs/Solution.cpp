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

class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> vec(n+1);
        return recurse(n, vec);
    }

    int recurse(int n, vector<int>& vec) {
        if ( 1 == n || 0 == n ) return 1;
        if ( vec[n] > 0 ) return vec[n];
        return vec[n] = recurse(n-1, vec) + recurse(n-2, vec);
    }
};


class Solution3 {
public:
    int climbStairs(int n) {
        vector<int> arr(n+1);
        arr[1] = 1; arr[2] = 2;
        for (int i = 3; i <= n; i ++ ) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};

