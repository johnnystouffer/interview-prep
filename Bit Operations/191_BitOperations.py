"""
191. Number of One Bits

Easy bit problem, basically we want to find
out the amount of one bits in a number

this is done by anding n with 1 (XXX & 001)
if this is true we got one
"""

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count = count + 1 if n & 1 else count
            n >>= 1
        return count