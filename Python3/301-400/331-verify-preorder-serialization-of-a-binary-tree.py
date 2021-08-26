#331. Verify Preorder Serialization of a Binary Tree (Python3) - 28ms/94.13% 14.2MB/89.52%
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        valid_children = [0]
        for elem in preorder.split(","):
            if valid_children == [1]:
                # There are additional elements remaining after the parse completed
                return False
            if elem == '#':
                valid_children[-1] += 1
                while (valid_children[-1] == 2):
                    valid_children.pop()
                    valid_children[-1] += 1 # Won't ever be out of bounds
            else:
                valid_children.append(0)
        return valid_children == [1]