class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        # if all([w.isupper() for w in word]):
        #     return True
        # first_cap = False
        # for i, w in enumerate(word):
        #     if word[i].isupper() and i == 0:
        #         first_cap = True
        #     elif word[i].isupper() and i != 0:
        #         return False
        # return True
        return word.isupper() or word.islower() or word.istitle()