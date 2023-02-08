class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # outputs = []
        # for i in range(1, n+1):
        #     if i % 3 == 0 and i % 5 != 0:
        #         outputs.append('Fizz')
        #     elif i % 3 !=0  and i % 5 == 0:
        #         outputs.append('Buzz')
        #     elif i % 3 == 0 and i % 5 == 0:
        #         outputs.append('FizzBuzz')
        #     else:
        #         outputs.append(str(i))
        # return outputs
        return ['Fizz' * (not i % 3) + 'Buzz' * (not i % 5) or str(i) for i in range(1, n+1)]
