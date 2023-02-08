class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] != '.':
                    ret_v = self.helper(i, j, board)
                    if not ret_v:
                        return False
        return True

    @staticmethod
    def helper(row, col, board):
        possible_inputs = {str(v): 0 for v in range(1, 10)}

        for x in range(0, len(board)):
            if board[x][col] != '.':
                if x != row and board[x][col] == board[row][col]:
                    return False

        for y in range(0, len(board)):
            if board[row][y] != '.':
                if y != col and board[row][y] == board[row][col]:
                    return False

        # check 3*3 grid
        range_x_start, range_y_start = 0, 0
        if row <= 2:
            range_x_start = 0
        elif row <= 5:
            range_x_start = 3
        elif row <= 8:
            range_x_start = 6

        if col <= 2:
            range_y_start = 0
        elif col <= 5:
            range_y_start = 3
        elif col <= 8:
            range_y_start = 6

        for i in range(range_x_start, range_x_start+3):
            for j in range(range_y_start, range_y_start+3):
                if board[i][j] != '.':
                    if (i != row or j != col) and board[i][j] == board[row][col]:
                        return False

        return True
