#!/usr/bin/env python
# coding=utf-8
my_board = [['.', '.', '9', '7', '4', '8', '.', '.', '.'],
            ['7', '.', '.', '.', '.', '.', '.', '.', '.'],
            ['.', '2', '.', '1', '.', '9', '.', '.', '.'],
            ['.', '.', '7', '.', '.', '.', '2', '4', '.'],
            ['.', '6', '4', '.', '1', '.', '5', '9', '.'],
            ['.', '9', '8', '.', '.', '.', '3', '.', '.'],
            ['.', '.', '.', '8', '.', '3', '.', '2', '.'],
            ['.', '.', '.', '.', '.', '.', '.', '.', '6'],
            ['.', '.', '.', '2', '7', '5', '9', '.', '.']]


outputs = [['5', '1', '9', '7', '4', '8', '6', '3', '2'],
           ['7', '8', '3', '6', '5', '2', '4', '1', '9'],
           ['4', '2', '6', '1', '3', '9', '8', '7', '5'],
           ['3', '5', '7', '9', '8', '6', '2', '4', '1'],
           ['2', '6', '4', '3', '1', '7', '5', '9', '8'],
           ['1', '9', '8', '5', '2', '4', '3', '6', '7'],
           ['9', '7', '5', '8', '6', '3', '1', '2', '4'],
           ['8', '3', '2', '4', '9', '1', '7', '5', '6'],
           ['6', '4', '1', '2', '7', '5', '9', '8', '3']]


class Solution(object):
    def sudoku_solver(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.backtracking(row=0, col=0, board=board)

    def backtracking(self, row, col, board):

        if self.is_full(board):
            return True

        if board[row][col] != '.':
            if col == len(board)-1 and row != len(board)-1:
                return self.backtracking(row=row+1, col=0, board=board)
            else:
                return self.backtracking(row=row, col=col+1, board=board)

        # get possible inputs
        possible_inputs = self.helper(row, col, board)
        # if there is no possible inputs
        if len(possible_inputs) == 0:
            return False

        # move forwards
        if board[row][col] == '.':
            for v in possible_inputs:
                board[row][col] = v
                if col == len(board)-1 and row != len(board)-1:
                    ret_v = self.backtracking(row=row+1, col=0, board=board)
                    if not ret_v:
                        board[row][col] = '.'
                else:
                    ret_v = self.backtracking(row=row, col=col+1, board=board)
                    if self.is_full(board):
                        return True

                    if not ret_v:
                        board[row][col] = '.'

    @staticmethod
    def helper(row, col, board):
        if board[row][col] != '.':
            return []

        possible_inputs = {str(v): 0 for v in range(1, 10)}

        for x in range(0, len(board)):
            if board[x][col] != '.':
                possible_inputs[board[x][col]] = 1

        for y in range(0, len(board)):
            if board[row][y] != '.':
                possible_inputs[board[row][y]] = 1

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
                    possible_inputs[board[i][j]] = 1

        return [k for k, v in possible_inputs.items() if v == 0]

    @staticmethod
    def is_full(_board):
        for i in range(1, len(_board)):
            for j in range(1, len(_board)):
                if _board[i][j] == '.':
                    return False
        return True


def print_board(board):
    print('---------------------------------------')
    for i in range(0, 9):
        for j in range(0, 9):
            print '|' if j == 0 else '', board[i][j], '|' if (j+1) % 3 == 0 else '',
        if (i+1) % 3 == 0:
            print('\n---------------------------------------')
        else:
            print('\n')

if __name__ == '__main__':

    _board = [['.', '.', '.', '.', '.', '.', '.', '6', '.'],
              ['8', '.', '9', '.', '.', '3', '.', '.', '.'],
              ['.', '7', '.', '4', '.', '2', '5', '.', '8'],
              ['.', '6', '.', '.', '.', '.', '4', '3', '.'],
              ['.', '.', '8', '.', '9', '.', '.', '5', '.'],
              ['5', '.', '.', '2', '.', '.', '9', '.', '.'],
              ['3', '8', '2', '5', '.', '.', '.', '.', '.'],
              ['.', '.', '.', '.', '.', '.', '6', '.', '.'],
              ['.', '5', '.', '.', '.', '.', '.', '2', '.']]

    s = Solution()
    s.sudoku_solver(_board)
    print_board(_board)

