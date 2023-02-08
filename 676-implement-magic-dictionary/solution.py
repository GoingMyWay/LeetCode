class MagicDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        pass

    def buildDict(self, words):
        """
        Build a dictionary through a list of words
        :type dict: List[str]
        :rtype: void
        """
        self.w_set = set(words)
        self.d = collections.Counter(nei for word in self.w_set for nei in self._gen_neighbors(word))

    def search(self, word):
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        :type word: str
        :rtype: bool
        """
        return any(
            (self.d[nei] > 1) or (self.d[nei] == 1 and word not in self.w_set) 
            for nei in self._gen_neighbors(word)
        )
    
    @staticmethod
    def _gen_neighbors(word):
        for i in range(len(word)):
            yield word[:i] + '*' + word[i+1:]


# class MagicDictionary(object):

#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self.buckets = collections.defaultdict(list)        

#     def buildDict(self, words):
#         """
#         Build a dictionary through a list of words
#         :type dict: List[str]
#         :rtype: void
#         """
#         for word in words:
#             self.buckets[len(word)].append(word)

#     def search(self, word):
#         """
#         Returns if there is any word in the trie that equals to the given word after modifying exactly one character
#         :type word: str
#         :rtype: bool
#         """
#         return any(sum(v1!=v2 for v1, v2 in zip(w, word)) == 1 for w in self.buckets[len(word)])

# Your MagicDictionary object will be instantiated and called as such:
# obj = MagicDictionary()
# obj.buildDict(dict)
# param_2 = obj.search(word)