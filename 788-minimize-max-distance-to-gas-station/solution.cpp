class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        const auto [minv, maxv] = minmax_element(stations.begin(), stations.end());
        // double left = 0, right = 1e8;
        double left = 0, right = *maxv - *minv;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            if (isPossible(mid, stations, k)) right = mid;
            else left = mid;
        }
        return left;
    }

private:
    bool isPossible(double D, vector<int>& stations, int k) {
        int used = 0;
        for (int i = 0; i < stations.size() - 1; ++i)
            used += (int) ((stations[i+1] - stations[i]) / D);
        return used <= k;
    }
};
