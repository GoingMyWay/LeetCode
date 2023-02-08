class Solution {
public:
    int nthUglyNumber(int n) {
        return solution1(n);
        // return solution2(n);
    }

    int solution1(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        int product2 = 1, product3 = 1, product5 = 1;
        vector<int> ugly(n+1, -1);
        int p = 1;

        while (p <= n) {
            int minv = min(min(product2, product3), product5);
            ugly[p] = minv;
            p ++;
            if (minv == product2) {
                product2 = 2 * ugly[p2];
                p2 ++;
            }
            if (minv == product3) {
                product3 = 3 * ugly[p3];
                p3 ++;
            }
            if (minv == product5) {
                product5 = 5 * ugly[p5];
                p5 ++;
            }
        }
        return ugly[n];
    }

    int solution2(int n) {
        vector<int> primes = {2, 3, 5};
        using state = pair<long, pair<int, int>>;
        priority_queue<state, vector<state>, greater<state>> pq;

        for (int i = 0; i < primes.size(); i ++) {
            pq.push({1, {primes[i], 1}});
        }

        vector<long> ugly(n+1);
        int p = 1;
        while (p <= n) {
            state pair = pq.top(); pq.pop();
            long product = pair.first;
            int prime = pair.second.first;
            int index = pair.second.second;

            if (product != ugly[p - 1]) {
                ugly[p] = product;
                p ++;
            }

            pq.push({ugly[index]*prime, {prime, index+1}});
        }
        return ugly[n];
    }
};
