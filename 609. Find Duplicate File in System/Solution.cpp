class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hashMap;
        for ( auto dir_file : paths ) {
            istringstream iss(dir_file);
            vector<string> tokens{istream_iterator<string>{iss},
                      istream_iterator<string>{}};
            string path = tokens[0];
            for ( int i = 1; i < tokens.size(); i ++ ) {
                int idx = tokens[i].find("(");
                string content = tokens[i].substr(idx+1);
                hashMap[content].push_back(path + "/" + tokens[i].substr(0, idx));
            }
        }
        for ( auto it: hashMap ) {
            if ( it.second.size() > 1 ) {
                result.push_back(it.second);
            }
        }
        return result;
    }
};

