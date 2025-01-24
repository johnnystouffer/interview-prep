from typing import List

"""
167. Two Sum II -> Input Array is Sorted

Now the reason why a sorted array makes this so much better is
pretty simple, the larger numbers are at the right, the smaller
numbers are on the left. 

Therefore if you add two numbers and it is too big, then maybe go
left on the list a bit and vice versa, which is exactly what this
solution does, if the l + r is too big, then r moves left one to
a smaller number, if the number is too small, we move l one over
"""

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1

        while l < r:
            s = numbers[l] + numbers[r]
            
            if target == s:
                return [l+1, r+1]
            if target > s:
                l += 1
            else:
                r -= 1
