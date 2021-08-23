#9. Palindrome Number (Python3) - 44ms/98.18% 14.1MB/92.67%
class Solution:
    def isPalindrome(self, x: int) -> bool:
		# Shortcutting negative numbers saves 15ms
        if x < 0:
            return False
        xstr = str(x)
        l = len(xstr)//2 # Integer division works for both even and odd numbers
        return xstr[:l] == xstr[::-1][:l]