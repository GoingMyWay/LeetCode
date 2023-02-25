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

    // 定义：速度为 x 时，需要 f(x) 小时吃完所有香蕉
    // f(x) 随着 x 的增加单调递减
    int f(vector<int>& piles, int x) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += piles[i] / x;
            if (piles[i] % x > 0) {
                hours++;
            }
        }
        return hours;
    }
};


