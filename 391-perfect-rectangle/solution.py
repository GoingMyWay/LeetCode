class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        X1, Y1 = float('inf'), float('inf')
        X2, Y2 = -float('inf'), -float('inf')
        
        points = set()
        actual_area = 0
        for x1, y1, x2, y2 in rectangles:
            # 计算完美矩形的理论顶点坐标
            X1, Y1 = min(X1, x1), min(Y1, y1)
            X2, Y2 = max(X2, x2), max(Y2, y2)
            # 累加小矩形的面积
            actual_area += (x2 - x1) * (y2 - y1)
            # 记录最终形成的图形中的顶点
            p1, p2 = (x1, y1), (x1, y2)
            p3, p4 = (x2, y1), (x2, y2)
            for p in [p1, p2, p3, p4]:
                if p in points: points.remove(p)
                else:           points.add(p)
        # 判断面积是否相同
        expected_area = (X2 - X1) * (Y2 - Y1)
        if actual_area != expected_area:
            return False
        # 判断最终留下的顶点个数是否为 4
        if len(points) != 4:       return False
        # 判断留下的 4 个顶点是否是完美矩形的顶点
        if (X1, Y1) not in points: return False
        if (X1, Y2) not in points: return False
        if (X2, Y1) not in points: return False
        if (X2, Y2) not in points: return False
        # 面积和顶点都对应，说明矩形符合题意
        return True
