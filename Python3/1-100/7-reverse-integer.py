#7. Reverse Integer (Python3) - 16ms/99.95% 14.2MB/73.79%
class Solution:
    def reverse(self, x: int) -> int:
        revx = int(str(abs(x))[::-1])
        if x < 0:
            return 0 if revx > 0x80000000 else -1 * revx
        return 0 if revx > 0x7FFFFFFF else revx