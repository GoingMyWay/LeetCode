class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        // for (int i = 0; i < height.size(); i ++) {
        while (left < right) {
            int currArea = min(height[left], height[right]) * (right - left);
            res = max(res, currArea);
            if (height[left] < height[right]) {
                left ++;
            } else {
                right --;
            }
        }
        return res;
    }
};