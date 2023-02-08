class Solution {
public:
    vector<vector<int>> dirs = {
                {-1, 0},
        {0, -1},        {0, 1},
                {1, 0}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        using state = pair<int, pair<int, int>>;

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effortTo(m, vector<int>(n, INT_MAX));
        effortTo[0][0] = 0;

        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({0, {0, 0}});

        while (pq.size() > 0) {
            pair<int, pair<int, int>> curState = pq.top(); pq.pop();
            int curEffortFromStart = curState.first;
            int curX = curState.second.first;
            int curY = curState.second.second;

            if (curEffortFromStart > effortTo[curX][curY]) {
                continue;
            }

            if (curX == m - 1 && curY == n - 1) {
                return curEffortFromStart;
            }

            for (vector<int> & dir: dirs) {
                int nextX = curX + dir[0];
                int nextY = curY + dir[1];
                if (nextX >= m || nextX < 0 || nextY >= n || nextY < 0) {
                    continue;
                }
                int effortToNextNode = max(
                    effortTo[curX][curY], 
                    abs(heights[curX][curY] - heights[nextX][nextY])
                );
                if (effortTo[nextX][nextY] > effortToNextNode) {
                    effortTo[nextX][nextY] = effortToNextNode;
                    pq.push({effortToNextNode, {nextX, nextY}});
                }
            }
        }
        return 0;
    }
};

