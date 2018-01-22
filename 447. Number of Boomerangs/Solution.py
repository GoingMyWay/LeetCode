#!/usr/bin/env python
# coding=utf-8
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        result = 0
        for x1, y1 in points:
            dist_map = {}
            for x2, y2 in points:
                dist = (x1-x2)**2 + (y1-y2)**2
                dist_map[dist] = dist_map.get(dist, 0) + 1
                    
            for dist, count in dist_map.items():
                result += count * (count - 1)

        return result

