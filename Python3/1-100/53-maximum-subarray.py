#53. Maximum Subarray (Python3) - 98ms/8.26% 15.1MB/60.04%
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum_so_far, largest = 0, float("-inf")
        for num in nums:
            sum_so_far = max(num, sum_so_far + num)
            largest = max(largest, sum_so_far)
        return largest