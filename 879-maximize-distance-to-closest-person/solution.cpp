class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = 0, r = 0, res = 1, dist = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (0 == seats[i]) r ++;
            else {
                r = i;
                if (seats[l] == 0) res = r - l;
                else {
                    if ((r-l-1) % 2 == 0) dist = (r-l-1) / 2;
                    else dist = (r-l) / 2;
                    
                    if (dist > res) res = dist;              
                }
                l = i;
            }
        }
        return res > r-l ? res : r-l;
    }
};
