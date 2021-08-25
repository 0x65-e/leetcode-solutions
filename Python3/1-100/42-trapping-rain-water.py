#42. Trapping Rain Water (Python3) - 7548ms/5.02% 16.1MB/5.58%
class Solution:
    def trap(self, height: List[int]) -> int:
        # Represent water as existing in pool levels
        # E.g. water can exist at level 0, level 1, level 2, the same as elevations, so long
        # as there is a higher elevation on both sides. A height of 3 bounds pool levels 0, 1, and 2 (but not 3)
        pools = max(height) * [None]
        water, prev_h = 0, height[0]
        for i, h in enumerate(height):
            if h < prev_h:
                #for level in range(h, prev_h):
                #    pools[level] = i
                pools[h:prev_h] = [i] * (prev_h - h)
            else:
                for level in range(prev_h, h):
                    lwall = pools[level]
                    if lwall != None:
                        water += i - lwall
            prev_h = h
        return water