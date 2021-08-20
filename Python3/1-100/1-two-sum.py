#1. Two Sum (Python3) - 56ms/88.22% 15.6MB/9.74%
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        halves = dict()
        for i, val in enumerate(nums):
            if val in halves:
                return [halves.get(val), i]
            halves[target-val] = i