class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
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