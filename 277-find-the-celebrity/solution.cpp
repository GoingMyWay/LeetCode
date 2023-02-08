/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for (int other = 1; other < n; other++) {
            if (!knows(other, cand) || knows(cand, other)) {
                cand = other;
            } else {
            }
        }
        
        for (int other = 0; other < n; other++) {
            if (cand == other) continue;
            if (!knows(other, cand) || knows(cand, other)) {
                return -1;
            }
        }
        return cand;
    }
};
