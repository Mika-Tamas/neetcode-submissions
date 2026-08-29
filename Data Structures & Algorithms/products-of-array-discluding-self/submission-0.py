class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = []
        for i in range(len(nums)):
            product = 1
            for n in range(len(nums)):
                if n == i:
                    continue
                else:
                    product = product * nums[n]
            output.append(product)
        return output
            