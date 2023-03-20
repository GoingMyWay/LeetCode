class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, i = 0;
        while (i <= flowerbed.size() - 1) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i-1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)
            ) {
                flowerbed[i] = 1;
                count += 1;
            }
            i += 1;
            if (count >= n) return true;
        }
        return false;
    }
};
