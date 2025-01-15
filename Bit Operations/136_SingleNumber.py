from typing import List

"""
136. Single Number

This questions wants you to find the number that does repeat
in the array, HOWEVER we are constrained in time complexity
to O(n) and space complexity to O(1)... this immediately throws
out the idea of a hash table to store what we have seen so far
Additionally we cannot make a nested loop.

We still can do this (obviously) with bit tricks. Hear me out:
XOR is exclusive or, and if you have duplicate numbers XORed, 
the number will be zero, so if you XOR all but the single number
the only number left is the only one without a duplicate
"""

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        og_num = 0
        for num in nums:
            og_num ^= num
        return og_num