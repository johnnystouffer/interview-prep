from typing import List

"""
90 - Subsets II
Difficulty -> Medium

This is similar to Subsets I as (obviously) we are find all the 
possible subsets of the given array. The main trick is that we 
have duplicates in this one which throws it off as our original
strategy would have allowed for repeating sets which is literally
contradicts the purpose of sets

We can add the value and then after when we do not add the other
make sure that the next values are not the same. In which we 
would skip it.

The time complexity of this solution is O(n * 2^n) since the
hwight of the recursion tree is n, and it will (in worst case)
double for each level. then n because we move down the list with
the while loop
"""

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        def recursion(currList, i, nums):
            # base case length nums == i means done with stack
            if len(nums) == i:
                allLists.append(currList.copy())
                return

            # do not include this one into the subset
            currList.append(nums[i])
            recursion(currList, i + 1, nums)
            currList.pop()
            # add current number
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            # include it
            recursion(currList, i + 1, nums)
            # back tracking
            return

        allLists = []
        recursion([], 0, sorted(nums))
        return allLists