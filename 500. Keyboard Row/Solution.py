class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        keyboard  = ['QWERTYUIOP', 'ASDFGHJKL', 'ZXCVBNM']
        outputs = []
        for word in words:
            if all([v in keyboard[0] for v in word.upper()]) or all([v in keyboard[1] for v in word.upper()]) or all([v in keyboard[2] for v in word.upper()]):
                outputs.append(word)
        return outputs