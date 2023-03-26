class UF {
public:
    UF(int n) : n (n) {
        parents = vector<int>(n, 0);
        for (int i = 0; i < n; i ++) {
            parents[i] = i;
        }
    }

    void unionNodes(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI == rootJ) return;
        parents[rootI] = rootJ;
        n --;
    }

    int find(int x) {
        if (parents[x] != x) parents[x] = find(parents[x]);
        return parents[x];
    }
    
private:
    int n;
    vector<int> parents;
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = nums.size();
        UF uf(n);
        unordered_set<int> set;
        unordered_map<int, int> numIDs;
        for (int i = 0; i < n; i ++) {
            numIDs[nums[i]] = i;
            set.insert(nums[i]);
        }

        for (int num : set) {
            if (set.count(num - 1)) // it is not the first value in a consecutive sequence
                continue;

            // num could be the first value in a consecutive sequence
            int curNum = num;
            while (set.count(curNum+1)) {
                uf.unionNodes(numIDs[curNum], numIDs[curNum+1]);
                curNum += 1;
            }
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i ++) {
            res[uf.find(i)] += 1;
        }
        return *max_element(res.begin(), res.end());
    }
};