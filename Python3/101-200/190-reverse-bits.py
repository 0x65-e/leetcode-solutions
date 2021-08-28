#190. Reverse Bits (Python3) - 24ms/97.29% 14MB/88.69%
class Solution:
    def reverseBits(self, n: int) -> int:
        return int('{0:032b}'.format(n)[::-1], 2)
