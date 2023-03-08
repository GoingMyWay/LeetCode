class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 1LL * (*max_element(time.begin(), time.end())) * totalTrips;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (isEnoughTime(time, mid, totalTrips)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool isEnoughTime(vector<int> & time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (auto t : time) {
            actualTrips += givenTime / t;
        }
        return actualTrips >= totalTrips;
    }

};
