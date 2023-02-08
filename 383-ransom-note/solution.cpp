class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> rmap;
        map<char, int> mmap;
        for (auto c: ransomNote) {
            rmap[c] += 1;
        }
        for (auto c: magazine) {
            mmap[c] += 1;
        }
        for (const auto& [key, value] : rmap) {
            if (mmap.count(key) != 1) {
                return false;
            } else {
                if (mmap[key] < value) return false; 
            }
        }
        return true;
    }
};