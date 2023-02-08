class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string mytargets = "";
        vector<string> result;
        for ( auto s: licensePlate ) {
            if ( (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') ) { mytargets += s; }
        }
        transform(mytargets.begin(), mytargets.end(), mytargets.begin(), ::tolower);
        unordered_map<char, int> wordmap;
        for ( auto s: mytargets ) {
            if ( wordmap.count(s) ) wordmap[s] += 1;
            else wordmap[s] = 1;
        }

        int minlength = 16;
        set<string> wordset;
        for ( auto ww: words ) {
            unordered_map<char, int> tempmap;
            for ( auto w: ww ) {
                if ( tempmap.count(w) ) tempmap[w] += 1;
                else tempmap[w] = 1;
            }
            int isMatch = 1;
            for ( auto & it : wordmap ) {
                if ( tempmap.count(it.first) && tempmap[it.first] >= it.second ) {
                    continue;
                } else {
                    isMatch = 0;
                    break;
                }
            }
            if ( isMatch ) {
                if ( (int)ww.size() <= minlength ) {
                    minlength = (int)ww.size();
                    wordset.insert(ww);
                }
            }
        }

        for ( auto ww: words ) {
            if ( (int)ww.size() == minlength && wordset.count(ww) ) result.push_back(ww);
        }
        return result[0];
    }
};
