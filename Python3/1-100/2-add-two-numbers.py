#2. Add Two Numbers (Python3) - 68ms/74.71% 14.3MB/73.48%
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode()
        curr = head
        carry, curr.val = divmod(l1.val + l2.val, 10) # guaranteed non-empty so this should be good
        while (l1.next != None and l2.next != None):
            curr.next = ListNode()
            curr = curr.next
            l1, l2 = l1.next, l2.next
            carry, curr.val = divmod(l1.val + l2.val + carry, 10)
        # Reuse nodes from the longer list if possible
        if l1.next != None:
            curr.next = l1.next
        elif l2.next != None:
            curr.next = l2.next
        # Propagate if last computation has a carry
        while (carry):
            if curr.next != None:
                curr = curr.next
            else:
                curr.next = ListNode()
                curr = curr.next
            carry, curr.val = divmod(curr.val + carry, 10)
            
        return head
            