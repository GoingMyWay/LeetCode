class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        self.graphs = self.build_graph(numCourses, prerequisites)
        
        # define variables
        self.visited = [False] * numCourses
        self.onpath = [False] * numCourses
        self.cycle = False

        self.poster_order = []

        for node in range(numCourses):
            self.dfs(node)
        
        if self.cycle:
            return []
        
        return reversed(self.poster_order)

    def build_graph(self, numCourses, prerequisites):
        graphs = [list() for _ in range(numCourses)]
        for edge in prerequisites:
            _from, _to = edge[1], edge[0]
            graphs[_from].append(_to)
        return graphs

    def dfs(self, src):
        if self.onpath[src]:
            self.cycle = True
        
        if self.visited[src] or self.cycle:
            return
        
        self.visited[src] = True
        self.onpath[src] = True
        
        for n in self.graphs[src]:
            self.dfs(n)
        
        self.poster_order.append(src)
        self.onpath[src] = False
