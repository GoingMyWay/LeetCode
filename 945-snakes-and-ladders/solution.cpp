class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        vector<pair<int, int>> cells(n*n+1);
        int index = 1;
        for (int row = n - 1; row >= 0; row--) {
            for (int column: columns) {
                cells[index++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
 
        queue<int> q;
        q.push(1);
        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        while (q.size() > 0) {
            int curr = q.front(); q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto const & [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column]: next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};
