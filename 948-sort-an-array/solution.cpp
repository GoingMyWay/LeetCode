class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (auto & v: nums) temp.push_back(0);
        sort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void sort(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return;
        int mid = lo + (hi - lo) / 2;
        sort(nums, lo, mid);
        sort(nums, mid+1, hi);
        merge(nums, lo, hi, mid);
    }

    void merge(vector<int>& nums, int lo, int hi, int mid) {
        for (int i = lo; i <= hi; i ++) temp[i] = nums[i];
        
        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p ++) {
            if (i > mid) {
                nums[p] = temp[j++];
            } else if (j > hi) {
                nums[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else {
                nums[p] = temp[i++];
            }
        }
    }

private:
    vector<int> temp;
};
