class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalTank = 0, currTank = 0;
        int startingIndex = 0;
        for (int i = 0; i < n; i ++) {
            totalTank += gas[i] - cost[i];
            currTank += gas[i] - cost[i];
            if (currTank < 0) {
                startingIndex = i + 1;
                currTank = 0;
            }
        }
        return totalTank >=0 ? startingIndex : -1;
    }
};