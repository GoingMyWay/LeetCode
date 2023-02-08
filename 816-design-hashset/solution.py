class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self._data = [False] * 1000000

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        self._data[key] = True

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        self._data[key] = False
        

    def contains(self, key):
        """
        Returns true if this set contains the specified element
        :type key: int
        :rtype: bool
        """
        return self._data[key]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)