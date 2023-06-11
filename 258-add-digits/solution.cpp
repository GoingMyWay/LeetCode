class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int newnum = 0;
        while (num != 0) {
            newnum += num % 10;
            num /= 10;
        }
        return addDigits(newnum);
    }
};
