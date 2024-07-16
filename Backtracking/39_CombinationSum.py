from typing import List

"""
39. Combination Sum
Difficulty -> Medium

I learned about Combinations back in high school in AP Stats however three
years later I learn the more inner workings of why this works the way it
does.

The solution to this is going to be O(n^target/min(candidates)) since this is
the formula for combinations because for each step you are chosing to include
a candidate or not, which puts the n, then target/min(candidates) due to the
max depth of recursion being target/min(candidates) since the worst case is
you keep adding the minimum till it reaches the target
"""

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def combRecurse(currList, currentSum, startIndex):
            # base case: if we meet the target
            if currentSum == target:
                allLists.append(currList.copy())
                return
            # if the current sum exceeds the target then we cannot use it
            if currentSum > target:
                return

            # explore further by including current and next candidates
            for i in range(startIndex, len(candidates)):
                currList.append(candidates[i])
                # we add it then let the list keep going on starting at i
                combRecurse(currList, currentSum + candidates[i], i)
                # backtrack for recurse
                currList.pop()

        allLists = []
        combRecurse([], 0, 0)
        return allLists
