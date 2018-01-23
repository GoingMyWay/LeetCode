class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (( citations.size() == 0 ) || ( *max_element(citations.begin(), citations.end()) == 0 )) { return 0; }
        
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0;
        while ( i < citations.size() ) {
            if ( citations[i] < i+1 ) { return i; }
            i ++;
        }
        return i;
    }
};

