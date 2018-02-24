class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for ( int i = 0; i < n; i ++ ) {
            while ( !st.empty() && temperatures[i] > temperatures[st.top()] ) {
                int idx = st.top(); st.pop();
                res[idx] = i - idx; 
            }
            st.push(i);
        }

        return res;
    }
};

class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int maxValue = 30001;
        vector<int> nextIndex(101, maxValue);
        vector<int> res(temperatures.size(), 0);
        for ( int i = temperatures.size()-1; i >= 0; --i ) {
            int warmerIndex = maxValue;
            for ( int j = temperatures[i]+1; j <= 100; ++j ) {
                if ( warmerIndex > nextIndex[j] ) warmerIndex = nextIndex[j];
            }
            if ( warmerIndex < maxValue ) res[i] = warmerIndex - i;
            
            nextIndex[temperatures[i]] = i; 
        }
        return res;
    }
}; 
