class Solution:
    def minimumLines(self, points: List[List[int]]) -> int:
        n, line_points = len(points), collections.defaultdict(set)               
        for i in range(n):                                                        # calculate `line_points`
            x1, y1 = points[i]
            for j in range(i+1, n):
                x2, y2 = points[j]
                if x1 == x2:                                                      # handle divided by zero case
                    a, b = x1, sys.maxsize                                        # for `b`, you can use any number not in range of [-100, 100]
                else:
                    a = (y2 - y1) / (x2 - x1)
                    b = y1 - a * x1
                line_points[(a, b)].add((x1, y1))
                line_points[(a, b)].add((x2, y2))
        lines = [line for line, points in line_points.items() if len(points) > 2] # filtering out lines that cover more than 3 points
        ans, m = math.ceil(n / 2), len(lines)                                     # based on Math, set default value for ans
        for i in range(1, 2**m):                                                  # bitmasking on `lines` (try out all combinations)
            j, cnt = 0, bin(i).count('1')                                         # cnt = number of line used for current masking
            cur_points = set()                                                    # current points covered on selected lines
            while i > 0:
                if i % 2:
                    cur_points |= line_points[lines[m-1-j]]                       # set union operaion on '1' bits
                i >>= 1                        
                j += 1
            ans = min(ans, cnt + math.ceil( (n-len(cur_points))/2 ))              # check if current masking is better
        return ans
