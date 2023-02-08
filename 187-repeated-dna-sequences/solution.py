class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        nums = []
        for i, v in enumerate(s):
            if v == 'A':
                nums.append(0)
            elif v == 'C':
                nums.append(1)
            elif v == 'G':
                nums.append(2)
            elif v == 'T':
                nums.append(3)
            else:
                raise ValueError("value {} not found!".format(v))
        
        res = set()
        seen = set()

        left, right = 0, 0
        hash_v = 0
        base = 4
        while (right < len(s)):
            hash_v = base * hash_v + nums[right]
            right += 1

            if (right - left == 10):
                if (hash_v in seen):
                    res.add(s[left:right])
                else:
                    seen.add(hash_v)
                hash_v = hash_v - nums[left] * (base ** (10-1))
                left += 1
        return list(res)
