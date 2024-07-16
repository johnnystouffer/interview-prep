from typing import List

"""
78. Subsets
Difficulty -> Medium

I learned about Subsets in my Discrete Math class mainly, or at
least that is where we discussed them most in depth. When
implementing subsets in Python I find the best decision for
readability and efficiency is Backtracking.

This solution will run in O(n * 2^n) because each level of the tree
will double and the amount of levels would be len(nums) or n, however
we need to multiply this by n due to the copying.
"""
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def subsetRecurse(currList, iterator):
            # Base case: if we go past the list we completed a subset
            if iterator == len(nums):
                allLists.append(currList.copy())
                return

            # Recurse without including the current num
            subsetRecurse(currList, iterator + 1)
            # Recurse including the current num
            currList.append(nums[iterator])
            subsetRecurse(currList, iterator + 1)
            # Pop from the list so the previous recurse can work properly
            currList.pop()

        allLists = []
        subsetRecurse([], 0)
        return allLists