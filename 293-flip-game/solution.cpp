class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> result;
        for (int i = 1; i < currentState.size(); i++) {
            if (currentState[i] == '+' && currentState[i - 1] == '+') {
                string res = currentState;
                res[i - 1] = '-';
                res[i] = '-';
                result.push_back(res);
            }
        }
        return result;
    }
};