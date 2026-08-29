class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        h = {}
        for i in range(len(nums)):
            h[target - nums[i]] = i
        for i in range(len(nums)):
            if nums[i] in h:
                if i != h[nums[i]]:
                    if i > h[nums[i]]:
                        return [h[nums[i]],i]
                    else:
                        return [i,h[nums[i]]]