class Solution(object):
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        outputs = []
        for number in range(left, right+1):
            for v in str(number):
                if int(v) == 0 or number % int(v) != 0:
                    break
            else:
                outputs.append(number)
        return outputs