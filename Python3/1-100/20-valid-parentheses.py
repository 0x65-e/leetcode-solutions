#20. Valid Parentheses (Python3) - 28ms/84.40% 14.4MB/8.07%
class Solution:
    def isValid(self, s: str) -> bool:
        sequence = [] # parentheses = 1, brackets = 2, braces = 3
        for c in s:
            if c == '(':
                sequence.append(1)
            elif c == ')':
                if len(sequence) == 0 or sequence.pop() != 1:
                    return False
            elif c == '[':
                sequence.append(2)
            elif c == ']':
                if len(sequence) == 0 or sequence.pop() != 2:
                    return False
            elif c == '{':
                sequence.append(3)
            elif c == '}':
                if len(sequence) == 0 or sequence.pop() != 3:
                    return False
        return len(sequence) == 0