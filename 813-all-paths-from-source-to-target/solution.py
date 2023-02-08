class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        
        def dfs(src, path):

            path.append(src)

            if src == len(graph) - 1:
                res.append(path[:])
                path.pop(-1)
                return
            
            for node in graph[src]:
                dfs(node, path)
        
            path.pop(-1)

        res = []
        dfs(0, list())
        return res
