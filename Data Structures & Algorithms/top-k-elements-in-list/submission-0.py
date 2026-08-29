class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        occur = {}
        freq = [[] for i in range(len(nums) + 1)]
        sol = []
        for num in nums:
            occur[num] = 1 + occur.get(num,0)

        for (key,value) in occur.items():
            freq[value].append(key)

        for i in range(len(freq)-1,0,-1):
            for n in freq[i]:
                sol.append(n)
                if len(sol) == k:
                    return sol

            