#202. Happy Number (Python3) - 32ms/81.66% 14.3MB/49.77%
class Solution:
    def isHappy(self, n: int) -> bool:
        prev_visited = set()
        prev_visited.add(n)
        while True:
            new_n = 0
            while (n > 0):
                new_n += (n % 10) ** 2
                n = n // 10
            if (new_n == 1):
                return True
            if new_n in prev_visited:
                return False
            prev_visited.add(new_n)
            n = new_n