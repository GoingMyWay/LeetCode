class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        self.graphs = self.build_graph(numCourses, prerequisites)
        
        # define variables
        self.visited = [False] * numCourses
        self.onpath = [False] * numCourses
        self.cycle = False

        for node in range(numCourses):
            self.dfs(node)

        return not self.cycle

    def build_graph(self, numCourses: int, prerequisites: List[List[int]]) -> List[List[int]]:
        graphs = [list() for _ in range(numCourses)]
        for edge in prerequisites:
            _from, _to = edge[1], edge[0]
            graphs[_from].append(_to)
        return graphs

    def dfs(self, src: int) -> None:
        if self.onpath[src]:
            self.cycle = True
        
        if self.visited[src] or self.cycle:
            return
        
        self.visited[src] = True
        self.onpath[src] = True
        
        for n in self.graphs[src]:
            self.dfs(n)
        
        self.onpath[src] = False
