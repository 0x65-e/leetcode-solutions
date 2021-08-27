#219. Contains Duplicate II (Python3) - 612ms/53.59% 26MB/81.53%
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if k == 0:
            return False
        l, subarray = 0, set(nums[:k])
        # Check for duplicates in the first k items
        if len(subarray) != len(nums[:k]):
            return True
        # Check if later items have a duplicate in the previous k
        for num in nums[k:]:
            if num in subarray:
                return True
            subarray.remove(nums[l]) # subarray will always contain the previous k items
            subarray.add(num)
            l += 1
        return False