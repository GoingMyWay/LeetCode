class Solution {
public:
    int trap2(vector<int>& height)
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
    
    int trap3(vector<int>& height) {
        if (height.size() == 0) return 0;
        int size = height.size();
        vector<int> leftMax(size), rightMax(size);
        leftMax[0] = height[0];
        for (int i = 1; i < size; i++) 
            leftMax[i] = max(height[i], leftMax[i-1]);
        rightMax[size-1] = height[size-1];
        for (int i = size-2; i >= 0; i--)
            rightMax[i] = max(height[i], rightMax[i+1]);
        
        int ans = 0;
        for (int i = 0; i < size; i ++) 
            ans += min(rightMax[i], leftMax[i]) - height[i];
        
        return ans;
    }

    int trap(vector<int>& height)
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

