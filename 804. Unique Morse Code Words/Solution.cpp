class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        for (auto w: words) {
            string result = "";
            for (auto c: w) {
                result += morse[c-a];
            }
            s.insert(result);
        }
        return s.size();
    }
};
