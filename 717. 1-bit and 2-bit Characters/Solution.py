class Solution(object):
    def isOneBitCharacter(self, bits):
        """
        :type bits: List[int]
        :rtype: bool
        """
        index = 0
        while index < len(bits):
            if bits[index] == 1:
                index += 2
                if index == len(bits):
                    return False
                elif index == len(bits)-1:
                    return True
            else:
                index += 1
        return True
