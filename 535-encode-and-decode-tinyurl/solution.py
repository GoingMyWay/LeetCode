class Codec:
    
    def __init__(self):
        self.url_map = {}
    
    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        tinyUrl = "http://tinyurl.com/" + ''.join(random.choice(string.ascii_letters+string.digits) for _ in range(6)) 
        self.url_map[tinyUrl] = longUrl
        return tinyUrl

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.url_map.get(shortUrl, shortUrl)


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))