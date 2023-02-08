class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string start;
        string target = "123450";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start.push_back(board[i][j]+'0');
            }
        }

        vector<vector<int>> neighbor = {
                {1, 3},
                {0, 4, 2},
                {1, 5},
                {0, 4},
                {3, 1, 5},
                {4, 2}
        };

        queue<string> q;
        set<string> visited;

        q.push(start);
        visited.insert(start);

        int step = 0;
        while (q.size() > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (target == cur) {
                    return step;
                }
                int idx = 0;
                for (; cur[idx] != '0'; idx++) ;
                for (int adj : neighbor[idx]) {
                    string new_board = swap(cur, adj, idx);
                    if (visited.count(new_board) == 0) {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            step++;
        }
        return -1;
    }
    
    string swap(string s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return s;
    }
};
