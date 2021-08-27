#152. Find Minimum in Rotated Sorted Array (Python3) - 52ms/9.94% 14.6MB/29.90%
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]
        l, r = 0, len(nums)-1
        while (r - l) > 1:
            mid = (r + l) // 2
            if nums[mid] > nums[l]:
                l = mid
            else:
                r = mid
        return nums[r]