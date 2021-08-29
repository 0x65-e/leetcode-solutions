#330. Patching Array (Python3) - 56ms/89.64% 14.3MB/86.01%
class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        total, patches = 0, 0
        for num in nums:
            while (total < num - 1):
                # Add the next lowest number that can't be formed from the sum of all previous numbers,
                # which is one more than the current total of all previous numbers
                total += total + 1
                patches += 1 # We had to add it so it's a patch
                if total >= n:
                    return patches
            # We extend our range by num, because we're guaranteed to form all numbers from 1 to total
            # (which may be more than num, but is at least num-1)
            # from the while statement, and we can form the next num numbers by forming num + (1...total)
            total += num
            # Quit early if we know we can form the total
            if total >= n:
                return patches
        # Backup loop in case n wasn't reached from all the elements
        while (total < n):
            total += total + 1 # Same logic as before
            patches += 1
        return patches
