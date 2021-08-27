#11. Container With Most Water (Python3) - 740ms/63.36% 27.6MB/56.76%
class Solution:
    def maxArea(self, height: List[int]) -> int:
        lpointer, rpointer = 0, len(height) - 1
        maxArea = -1
        while (lpointer != rpointer):
            maxArea = max(min(height[lpointer], height[rpointer]) * (rpointer - lpointer), maxArea)
            if (height[lpointer] < height[rpointer]):
                lpointer += 1
            else:
                rpointer -= 1
        return maxArea