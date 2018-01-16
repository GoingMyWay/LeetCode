#!/usr/bin/env python
# coding=utf-8
class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.backtracking(row=0, col=0, board=board)

    def backtracking(self, row, col, board):

        if self.is_full(board) or (row == 8 and col == 9):
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

