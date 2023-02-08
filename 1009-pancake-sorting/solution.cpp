class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        sort(res, arr, arr.size());
        return res;
    }

    void sort(vector<int> & res, vector<int>& arr, int n) {
        if (n == 1) return;

        int maxVal = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i ++) {
            if (arr[i] > maxVal) {
                maxIndex = i;
                maxVal = arr[i];
            }
        }

        reverse(arr, 0, maxIndex);
        res.push_back(maxIndex+1);
        reverse(arr, 0, n-1);
        res.push_back(n);
        sort(res, arr, n-1);
    }

    void reverse(vector<int> & arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i ++;
            j --;
        }
    }
};