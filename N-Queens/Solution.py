class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        self.result = []
        positions = ['.'*n]*n
        self.back_tracking(n, 0, positions)
        return self.result

    def back_tracking(self, n, row, positions):
        if n == row:
            self.result.append(positions[:])
            return

        for col in range(n):
            if self.is_valid(row, col, positions):
                positions[row] = positions[row][:col] + 'Q' + positions[row][col+1:]
                self.back_tracking(n, row+1, positions)
                positions[row] = positions[row][:col] + '.' + positions[row][col+1:]

    def is_valid(self, row, col, positions):
        queen = 0
        is_safe = True
        while queen < row:
            if positions[queen].index('Q') == col or queen == row or \
                            (queen - positions[queen].index('Q')) == (row - col) or \
                            (queen + positions[queen].index('Q')) == (row + col):
                is_safe = False
                break
            queen += 1
        return is_safe

# if __name__ == '__main__':
#     s = Solution()
#     s.solveNQueens(4)
