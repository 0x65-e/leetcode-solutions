#206. Reverse Linked List (Python3) - 32ms/88.76% 15.4MB/93.48%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, curr = None, head
        while (curr != None):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
