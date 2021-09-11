#848. Shifting Letters (Python3) - 779ms/95.11% 27.3MB/84.97%
class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        out, start = [None] * len(s), ord("a")
        total = 0
        for i in range(len(s)-1,-1,-1):
            total += shifts[i]
            out[i] = chr((ord(s[i]) - start + total) % 26 + start)
        return "".join(out)
