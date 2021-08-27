#217. Contains Duplicate (Python3) - 116ms/78.50% 20.2MB/35.54%
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)