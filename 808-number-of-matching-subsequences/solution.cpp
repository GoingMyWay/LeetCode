class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> map_t(256);
        for(int i = 0; i < s.size(); i ++){
            map_t[s[i]].push_back(i);
        }

        int count = 0;
        for (auto & w: words) {
            count += (int)isSubsequence(w, s, map_t);
        }
        return count;
    }

    bool isSubsequence(string s, string t, unordered_map<char, vector<int>> & map_t) {
        // 二分查找
        int m = s.size(), n = t.size();
        // 串t指针
        int j = 0;
        // 借助map查找s[i]
        for (int i = 0; i < m; i++) {
            if (!map_t.count(s[i])) {
                // s[i]不在t里，直接返回
                return false;
            }
            // 如果存在，在map[s[i]]中搜索比j大的最小索引即可：即二分搜索左侧边界的结果值
            int pos = leftBound(map_t[s[i]], j); // 传入的是s[i]在t中对应出现的所有下标索引
            if (pos == map_t[s[i]].size()) {
                // 二分搜索区间中没有找到s[i]
                return false;
            }
            j = map_t[s[i]][pos] + 1; // j 移动到二分搜索返回的pos处 后一位
        }
        return true;
    }

    int leftBound(vector<int>& vec_t, int j) {
        // 二分查找 搜索左侧边界 搜索j
        int left = 0, right = vec_t.size();
        // 左闭右开
        while (left < right) {
            int mid = left + (right - left)/2;
            if (vec_t[mid] < j) {
                left = mid + 1;
            } else if (vec_t[mid] > j) {
                right = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
