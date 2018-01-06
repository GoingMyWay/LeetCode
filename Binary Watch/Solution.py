class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        if num > 10 or num < 0:
            return []

        result = []

        def back_tracking(start, cnt, indices):
            if cnt == num:
                self.convert2time(result, indices)
                return
            for st in range(start+1, 10):
                back_tracking(st, cnt+1, indices+[st])
        back_tracking(-1, 0, [])
        return result

    @staticmethod
    def convert2time(result, indices):
        hour, minutes = 0, 0
        for v in indices:
            if v <= 3:
                hour += 2 ** (4-v-1)
            else:
                minutes += 2 ** (10-v-1)
        if hour <= 11 and minutes <= 59:
            result.append("%s:%s" % (hour, minutes) if minutes >= 10 else "%s:0%s" % (hour, minutes))
