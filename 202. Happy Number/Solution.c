bool isHappy(int n) {
    int x = n, y = n;
    while ( 1 ) {
        x = cal(x);
        y = cal(cal(y));
        if ( 1 == x ) return 1;
        if ( 1 == y ) return 1;
        if ( x == y ) return 0;
    }
}

int cal(int n) {
    int sum = 0;
    while ( n != 0 ) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

