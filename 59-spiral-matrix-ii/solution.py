class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        upper_bound, lower_bound = 0, n - 1
        left_bound, right_bound = 0, n - 1
        matrix = [[0]*n for _ in range(n)]
        count = 0
        while (count < n**2):
            # left -> right
            if (upper_bound <= lower_bound):
                for j in range(left_bound, right_bound+1):
                    matrix[upper_bound][j] = count + 1
                    count += 1
                upper_bound += 1
            
            # up -> down
            if (left_bound <= right_bound):
                for i in range(upper_bound, right_bound+1):
                    matrix[i][right_bound] = count + 1
                    count += 1
                right_bound -= 1
            
            # right -> left
            if (upper_bound <= lower_bound):
                for j in range(right_bound, left_bound-1, -1):
                    matrix[lower_bound][j] = count + 1
                    count += 1
                lower_bound -= 1
            
            # down -> up
            if (left_bound <= right_bound):
                for i in range(lower_bound, upper_bound-1, -1):
                    matrix[i][left_bound] = count + 1
                    count += 1
                left_bound += 1
        return matrix
            