class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        m, n = len(matrix), len(matrix[0])
        upper_bound, lower_bound = 0, m - 1
        left_bound, right_bound = 0, n - 1

        while (len(res) < m * n):
            # left -> right
            if (upper_bound <= lower_bound):
                for j in range(left_bound, right_bound+1):
                    res.append(matrix[upper_bound][j])
                upper_bound += 1
            # up -> down
            if (left_bound <= right_bound):
                for i in range(upper_bound, lower_bound+1):
                    res.append(matrix[i][right_bound])
                right_bound -= 1

            # right -> left
            if (upper_bound <= lower_bound):
                for j in range(right_bound, left_bound-1, -1):
                    res.append(matrix[lower_bound][j])
                lower_bound -= 1

            # down -> up
            if (left_bound <= right_bound):
                for i in range(lower_bound, upper_bound-1, -1):
                    res.append(matrix[i][left_bound])
                left_bound += 1
        return res
