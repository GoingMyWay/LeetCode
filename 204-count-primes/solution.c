int countPrimes(int n) {
    n --;
    int count = 0;
    while (n > 1)
    {
        int s = sqrt(n);
        bool flag = 1;
        for (int i = 2; i <= s; i++)
        {
            if (n % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            count ++;
        n--;   
    }
    return count;
}