#42. Trapping Rain Water (Python3) - 141ms/7.80% 15.7MB/10.58%
class Solution:
    def trap(self, height: List[int]) -> int:
        # Represent water as existing in pool levels
        # E.g. water can exist at level 0, level 1, level 2, the same as elevations, so long
        # as there is a higher elevation on both sides. A height of 3 bounds pool levels 0, 1, and 2 (but not 3)
        pool_walls = [(-1, float("inf"))]
        water = 0
        for i, h in enumerate(height):
            last_height = 0 # A shorter wall in front means that height of pool has already been counted
            # Get all walls that are shorter than this wall
            while (h >= pool_walls[-1][1]):
                left_wall, wall_height = pool_walls.pop()
                water += (i - left_wall) * (wall_height - last_height)
                last_height = wall_height
            if len(pool_walls) > 1:
                left_wall, wall_height = pool_walls[-1]
                water += (i - left_wall) * (h - last_height)
            pool_walls.append((i+1, h))
        return water