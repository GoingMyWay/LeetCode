class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        # outputs = []
        # for v1 in findNums:
        #     index = nums.index(v1)
        #     for v2 in nums[index:]:
        #         if v2 > v1:
        #             outputs.append(v2)
        #             break
        #     else:
        #         outputs.append(-1)
        # return outputs
        hash_map, stack = {}, []
        for v in nums:
            if len(stack) == 0 or v <= stack[-1]:
                stack.append(v)
            else:
                while len(stack) != 0 and v > stack[-1]:
                    hash_map[stack.pop()] = v
                stack.append(v)
    
        return [-1 if v not in hash_map else hash_map[v] for v in findNums]
