class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return solution2(nums);
    }

private:
    int solution1(vector<int>& nums) {
        int n = nums.size();
        long left = nums[0], right = nums[n - 1];
        int cnt = 0;
        for (int i = 0, j = n - 1; i < j;) {
            if (left == right) {
                i++;
                j--;
                left = nums[i];
                right = nums[j];
            } else if (left < right) {
                i++;
                left += nums[i];
                cnt++;
            } else if (left > right) {
                j--;
                right += nums[j];
                cnt++;
            }
        }
        return cnt;
    }

    int solution2(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int count = 0;
        long leftAccumVal = nums[left], rightAccumVal = nums[right];
        while (left < right) {
            if (leftAccumVal == rightAccumVal) {
                left ++;
                right --;
                leftAccumVal = nums[left];
                rightAccumVal = nums[right];
            } else {
                if (leftAccumVal > rightAccumVal) {
                    right --;
                    rightAccumVal += nums[right];
                    count ++;
                } else if (leftAccumVal < rightAccumVal) {
                    left ++;
                    leftAccumVal += nums[left];
                    count ++;
                }
            }
        }
        return count;
    }
};