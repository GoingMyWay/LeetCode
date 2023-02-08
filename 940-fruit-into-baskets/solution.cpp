class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> s;
        int left = 0, maxPicked = 0;

        for (int right = 0; right < fruits.size(); right ++) {
            s[fruits[right]] ++;
            while (s.size() > 2) {
                s[fruits[left]] --;
                if (s[fruits[left]] == 0) {
                    s.erase(fruits[left]);
                }
                left ++;
            }
            maxPicked = max(maxPicked, right - left + 1);
        }
        return maxPicked;
    }
};