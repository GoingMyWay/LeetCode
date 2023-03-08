class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000 + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int f(vector<int>& piles, int candidateK) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / candidateK + (int)(piles[i] % candidateK > 0);
        }
        return hours;
    }
};
