class Solution {
public:
    double average(vector<int>& salary) {
        int minv = *min_element(salary.begin(), salary.end());
        int maxv = *max_element(salary.begin(), salary.end());
        int sumv = accumulate(salary.begin(), salary.end(), 0);
        return (sumv - minv - maxv) / (double)(salary.size() - 2);
    }
};
