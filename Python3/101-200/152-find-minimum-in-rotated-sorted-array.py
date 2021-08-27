#152. Find Minimum in Rotated Sorted Array (Python3) - 38ms/66.93% 14.5MB/85.22%
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if nums[0] < nums[-1]:
            return nums[0]
        l, r = 0, len(nums)-1
        while l < r:
            mid = (r + l) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid
        return nums[l]