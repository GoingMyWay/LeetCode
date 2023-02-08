class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (int i = 0; i < word.size(); i ++) {
            if (isupper(word[i])) count ++;
        }
        return (count == 0) || 
               (isupper(word[0]) && (count == 1)) || 
               count == word.size();
    }
};
