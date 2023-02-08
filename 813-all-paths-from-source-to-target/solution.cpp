class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        vector<int> path;
        vector<vector<int>> results;

        function<void(int, vector<int>&)> backtrack = [&](int currNode, vector<int>& path) {
            path.push_back(currNode);
            if (currNode == target) {
                results.push_back(vector(path));
                path.pop_back();
                return;
            }
            for (int nextNode : graph[currNode]) {
                backtrack(nextNode, path);
            }
            path.pop_back();
        };

        backtrack(0, path);
        return results;
    }
};
