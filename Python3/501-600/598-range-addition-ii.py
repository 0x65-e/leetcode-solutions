#598. Range Addition II (Python3) - 68ms/75.61% 16.2MB/64.08%
class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        minx, miny = m, n
        for square in ops:
            minx, miny = min(minx, square[0]), min(miny, square[1])
        return minx * miny
