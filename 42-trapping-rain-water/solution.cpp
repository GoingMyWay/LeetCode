class Solution {
public:
    int trap1(vector<int>& height)
    {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
    
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0], rightMax[n-1] = height[n-1];
        for (int i = 1; i < n; i ++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        for (int i = n - 2; i >= 0; i --) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    int trap2(vector<int>& height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top(); st.pop();
                if (st.empty()) break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};
