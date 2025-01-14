from typing import Optional

"""
2. Add Two Numbers

The classic linked list problem

We want to iterate through both lists, and
add each value and whatever carried on from the
previous value. Additionally we continue with the
longest list as they might not be the same length

This runs at O(max(n, m)) where n = len(l1) and m = len(l2)
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # start a new list and carry value
        head = ListNode(-1)
        node = head
        carry = 0

        while l1 and l2:
            # add the values and determine the new carry value
            newVal = (l1.val + l2.val + carry) % 10
            carry = (l1.val + l2.val + carry) // 10

            node.next = ListNode(newVal)
            node = node.next

            l1 = l1.next
            l2 = l2.next

        while l1:
            newVal = (l1.val + carry) % 10
            carry = (l1.val + carry) // 10

            node.next = ListNode(newVal)
            node = node.next
            l1 = l1.next

        while l2:
            newVal = (l2.val + carry) % 10
            carry = (l2.val + carry) // 10

            node.next = ListNode(newVal)
            node = node.next
            l2 = l2.next

        if carry:
            node.next = ListNode(carry)

        return head.next






        