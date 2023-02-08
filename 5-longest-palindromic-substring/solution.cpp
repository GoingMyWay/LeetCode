class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int longestStartIdx = 0;
        int longestEndIdx= 0;
        
        for (int i = dp.size()-1; i >= 0; i--){
            for (int j = dp[0].size()-1; j >= i; j--){
                if (i == j                               // Base case: One character e.g. 'a'
                    || (s[i] == s[j] && j == i+1)        // Base case: Two equal characters e.g. "bb"
                    || (s[i] == s[j] && dp[i+1][j-1])){  
                    dp[i][j] = true;
                    if ((longestEndIdx - longestStartIdx) < (j - i)){
                        longestStartIdx = i;
                        longestEndIdx = j;
                    }
                }
            }
        }
        return s.substr(longestStartIdx, (longestEndIdx - longestStartIdx + 1));
    }
};