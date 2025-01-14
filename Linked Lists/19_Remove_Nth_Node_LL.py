from typing import Optional

"""
19. Remove Nth Node from End of the list

Another classic linked list problem. In this problem 
we want to remove the nth node from the last node in the list

We need to use the slow and fast pointer method to do this
the right pointer goes n nodes over first, then we iterate
until right does not have a next one

When we hit that one then left.next is the node we need to 
remove. Then we remove and return the new list
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # make a dummy (might need to remove the head)
        dummy = ListNode(-1)
        right = dummy
        left = dummy
        dummy.next = head

        # move the right pointer however many points away
        for i in range(n):
            right = right.next

        # slide it down to the end
        while right and right.next:
            left = left.next
            right = right.next

        # remove said Node
        left.next = None if not left.next else left.next.next

        # return the head
        return dummy.next
