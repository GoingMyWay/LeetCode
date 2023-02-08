class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        self.colors = [False] * n
        self.visited = [False] * n
        self.is_bipartie = True

        def dfs(src):
            if not self.is_bipartie: return

            self.visited[src] = True
            for node in graph[src]:
                if not self.visited[node]:
                    self.colors[node] = not self.colors[src]
                    dfs(node)
                else:
                    if self.colors[node] == self.colors[src]:
                        self.is_bipartie = False

        for i in range(n):
            if not self.visited[i]:
                dfs(i)
        return self.is_bipartie

