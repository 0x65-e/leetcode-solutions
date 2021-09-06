#1629. Slowest Key (Python3) - 56ms/70.22% 14.4MB/81.38%
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        longest, last, lkey = 0, 0, ''
        for time, key in zip(releaseTimes, keysPressed):
            duration = time - last
            if duration > longest or duration == longest and key > lkey:
                longest = duration
                lkey = key
            last = time
        return lkey
