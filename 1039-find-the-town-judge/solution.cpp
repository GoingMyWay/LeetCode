class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.size() < n - 1) {
            return -1;
        }
        
        vector<int> indegrees(n + 1);
        vector<int> outdegrees(n + 1);

        for (auto const & relation : trust) {
            outdegrees[relation[0]]++;
            indegrees[relation[1]]++; 
        }

        for (int i = 1; i <= n; i++) {
            if (indegrees[i] == n - 1 && outdegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};