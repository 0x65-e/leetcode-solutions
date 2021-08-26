#331. Verify Preorder Serialization of a Binary Tree (Python3) - 95ms/5.08% 14.4MB/15.40%
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        valid_parse, remainder = Solution.parse(preorder.split(","))
        return valid_parse and len(remainder) == 0
    
    @staticmethod
    def parse(elements):
        """Checks valid preorder traversal of a tree and returns the remaining elements after parsing"""
        if len(elements) > 0:
            if elements[0] == '#':
                return (True, elements[1:])
            left_valid, right_subtree = Solution.parse(elements[1:])
            right_valid, remainder = Solution.parse(right_subtree)
            return (left_valid and right_valid, remainder)
        return (False, [])