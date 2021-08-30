#19. Remove Nth Node From End of List (Python3) - 38ms/16.04% 14.1MB/92.00%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        curr = head
        for i in range(0, n):
            curr = curr.next # Guaranteed safe since n <= sz
        if curr == None: # n == sz, so the head is the node to remove
            return head.next
        tail_head = head
        while curr.next != None:
            curr = curr.next
            tail_head = tail_head.next
        tail_head.next = (tail_head.next).next
        return head
