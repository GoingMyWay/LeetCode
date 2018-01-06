class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        n--;
        while (n>1)
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
                count++;
            n--;
        }
        return count;
    }
};