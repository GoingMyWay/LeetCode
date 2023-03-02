class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n <= 2) {
            vector<int> res;
            for (int i = 0; i < n; i ++) res.push_back(i);
            return res;
        }

        vector<set<int>> neighbours(n);
        for (auto & edge : edges) {
            int start = edge[0], end = edge[1];
            neighbours[start].insert(end);
            neighbours[end].insert(start);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i ++) {
            if (neighbours[i].size() == 1) leaves.push_back(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (auto leaf : leaves) {
                int neighbour = *neighbours[leaf].begin();
                neighbours[neighbour].erase(leaf);
                if (neighbours[neighbour].size() == 1)
                    newLeaves.push_back(neighbour);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
