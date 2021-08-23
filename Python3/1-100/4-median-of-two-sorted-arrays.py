#4. Median of Two Sorted Arrays (Python3) - 92ms/66.49% 14.3MB/94.34%
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l1, l2 = len(nums1), len(nums2)
        total_len = l1 + l2
        if total_len & 0x1:
            # Odd length, median is exact
            middle = total_len // 2
            i = j = 0
            while (i < l1 and j < l2):
                if nums1[i] < nums2[j]:
                    if i + j == middle:
                        return nums1[i]
                    i += 1
                else:
                    if i + j == middle:
                        return nums2[j]
                    j += 1
            return nums1[middle - j] if i < l1 else nums2[middle - i]
        else:
            # Even length, median is an average
            m2 = total_len // 2
            m1 = m2 - 1
            m = 0.0
            i = j = 0
            while (i < l1 and j < l2):
                if nums1[i] < nums2[j]:
                    if i + j == m1:
                        m = nums1[i]
                    elif i + j == m2:
                        return (m + nums1[i]) / 2.0
                    i += 1
                else:
                    if i + j == m1:
                        m = nums2[j]
                    elif i + j == m2:
                        return (m + nums2[j]) / 2.0
                    j += 1
            if i + j <= m1:
                return (nums1[m1 - j] + nums1[m2 - j]) / 2.0 if i < l1 else (nums2[m1 - i] + nums2[m2 - i]) / 2.0
            else:
                return (m + nums1[m2 - j]) / 2.0 if i < l1 else (m + nums2[m2 - i]) / 2.0
                