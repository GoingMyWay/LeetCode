class UF {
public:
    UF(int n) {
        count = n;
        parent = vector<int>(n);
        for (int i = 0; i < n; i ++) {
            parent[i] = i;
        }
    }

    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        parent[rootP] = rootQ;
        count -= 1;
    }

    bool connect(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int getCount() {
        return count;
    }

private:
    int count;
    vector<int> parent;
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(); // row
        int n = board[0].size(); // column
        int dummy = m*n;
        UF uf(m*n+1);

        // left and right columns
        for (int i = 0; i < m; i ++) {
            if (board[i][0] != 'X') {
                uf.union_(i*n, dummy);
            }
        }
        for (int i = 0; i < m; i ++) {
            if (board[i][n-1] != 'X') {
                uf.union_(i*n+n-1, dummy);
            }
        }
        // top and bottom rows
        for (int j = 0; j < n; j ++) {
            if (board[0][j] != 'X') {
                uf.union_(j, dummy);
            }
        }
        for (int j = 0; j < n; j ++) {
            if (board[m-1][j] != 'X') {
                uf.union_((m-1)*n+j, dummy);
            }
        }
        // rest regions
        for (int i = 1; i < m - 1; i ++) {
            for (int j = 1; j < n - 1; j ++) {
                if (board[i][j] != 'X') {
                    // check up, down, left, right, 4 direction
                    // up
                    if (board[i-1][j] != 'X') uf.union_(i*n+j, (i-1)*n+j);
                    // down
                    if (board[i+1][j] != 'X') uf.union_(i*n+j, (i+1)*n+j);
                    // left
                    if (board[i][j-1] != 'X') uf.union_(i*n+j, i*n+j-1);
                    // right
                    if (board[i][j+1] != 'X') uf.union_(i*n+j, i*n+j+1);
                }
            }
        }

        // replace the board
        for (int i = 1; i < m - 1; i ++) {
            for (int j = 1; j < n - 1; j ++) {
                if (!uf.connect(i*n+j, dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};