#191. Number of 1 Bits (Python3) - 38ms/11.98% 14.1MB/66.97%
class Solution:
    def hammingWeight(self, n: int) -> int:
        return bin(n).count('1')
