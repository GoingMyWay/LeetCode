class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            fast = cal(cal(fast));
            slow = cal(slow);
        } while (fast != slow);
        if (1 == slow) return 1;
        else return 0;
    }
    
    int cal(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};