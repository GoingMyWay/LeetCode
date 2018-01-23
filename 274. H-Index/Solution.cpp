class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (( citations.size() == 0 ) || ( *max_element(citations.begin(), citations.end()) == 0 )) { return 0; }
        
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0;
        while ( i < citations.size() ) {
            if ((i+1 == citations[i]) || 
                ( i < citations.size()-1 && citations[i] > i+1 && i+2 > citations[i+1] )) { return i+1; }
            i ++;
        }
        return i;
    }
};

