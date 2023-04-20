class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        int start = 0;
        for (int i = 1; i <= path.size(); ++i) {
            if (path[i] == '/' || i == path.size()) {
                string part = path.substr(start + 1, i - start - 1);
                if (part == "" || part == ".") {
                    // ignore
                } else if (part == "..") {
                    if (!parts.empty()) parts.pop_back();
                } else {
                    parts.push_back(part);
                }
                start = i;
            }
        }
        string res = "";
        for (string part : parts) {
            res += "/" + part;
        }
        return res.empty() ? "/" : res;
    }
};
