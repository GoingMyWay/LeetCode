class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0);
        return res;
    }

    void backTrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col ++) {
            if (!isValid(board, row, col)) {
                continue;
            }
            board[row][col] = 'Q';
            backTrack(board, row+1);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string> board, int row, int col) {
        for (int i = 0; i <= row; i ++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >=0; i --, j --) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >=0 && j < board.size(); i --, j ++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

private:
    vector<vector<string>> res;
};