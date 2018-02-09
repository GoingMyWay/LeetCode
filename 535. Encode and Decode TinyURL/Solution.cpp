class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ascii = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        int m = 0, n = 35;
        string tinyUrl = "http://tinyurl.com/"\;
        for (int i = 0; i < 6; i ++ ) {
            int rd = rand() % (n-m+1) + m;
            tinyUrl += ascii[rd];
        }
        this->insert(tinyUrl, longUrl);
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (this->urlMap.find(shortUrl) == this->urlMap.end()) {
            return shortUrl;
        } else return this->urlMap[shortUrl];
    }
    
    void insert(string k, string v) {
        this->urlMap.insert(pair<string, string>(k, v));
    }
    
private:
    map<string, string> urlMap;

};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
