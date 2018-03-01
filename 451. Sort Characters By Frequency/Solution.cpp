class Solution { 
public:
    string frequencySort(string s) {
        unordered_map<char, int> counter;
        vector<string> sortedVec(s.size()+1, );
        string result = ;
        for ( auto c: s) counter[c] ++;
        for ( auto & it: counter ) {
            char ch = it.first;
            int n = it.second;
            sortedVec[n].append(n, ch);
        }
        for ( auto it = sortedVec.rbegin(); it != sortedVec.rend(); it ++ ) {
            result += *it;
        }
        return result;
    }
};

