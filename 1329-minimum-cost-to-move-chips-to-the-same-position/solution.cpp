class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for (int pos : position) {
            (pos % 2 == 1) ? ++odd : ++even;
        }
        return min(odd, even);
    }
};