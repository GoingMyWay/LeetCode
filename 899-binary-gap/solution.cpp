class Solution {
public:
    int binaryGap(int N) {
        vector<int> bin;
        decimalToBinary(N, bin);
        int l = 0, r = 0, max_dist = 0;
        for (int i = 0; i < bin.size(); i ++) {
            if (bin[i] == 1) {
                r = i;
                if (r-l > max_dist) max_dist = r-l;
                l = i;
            }
        }
        return max_dist;
    }
    
    void decimalToBinary(int v, vector<int> & res) {
        if (v != 0) {
            res.insert(res.begin(), v%2);
            decimalToBinary(v/2, res);
        }
    }
};
