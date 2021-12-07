#1290. Convert Binary Number in a Linked List to Integer (Python3) - 36ms/25.39% 14.2MB/40.21%

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        dec = 0
        while head != None:
            dec = dec * 2 + head.val
            head = head.next
        return dec
        