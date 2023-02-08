using ValID = pair<int, int>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<ValID> bak(nums.size());
        for (int i = 0; i < nums.size(); i ++) {
            bak[i] = {nums[i], i};
            temp.push_back({nums[i], i});
            count.push_back(0);
        }
        sort(bak, 0, bak.size() - 1);
        return count;
    }
    
    void sort(vector<ValID>& nums, int lo, int hi) {
        if (lo == hi) return;
        int mid = lo + (hi - lo) / 2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);
        merge(nums, lo, hi, mid);
    }

    void merge(vector<ValID>& nums, int lo, int hi, int mid) {
        for (int i = lo; i <= hi; i ++) temp[i] = nums[i];
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p ++) {
            if (i > mid) {
                nums[p] = temp[j++];
            } else if (j > hi) {
                nums[p] = temp[i++];
                count[nums[p].second] += j - mid - 1;
            } else if (temp[i].first > temp[j].first) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
                count[nums[p].second] += j - mid - 1;
            }
        }
    }

private:
    vector<ValID> temp;
    vector<int> count;
};