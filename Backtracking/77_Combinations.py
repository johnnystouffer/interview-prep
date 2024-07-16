from typing import List

"""
77. Combinations
Difficulty -> Medium

I attempted Combination Sum before this one which was much more
difficult then this one, as this one is a simple implementation
of Combinations

This solution will run in O(k * C(n, k)) where C(n, k) = 
n! / k! (n-k)!. It will run this way because we are finding
all of the combinations and our depth in recursion will be at k
"""

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def combRecurse(currList, currNum):
            # if our list has reached its end length return
            if len(currList) == k:
                allLists.append(currList.copy())
                return
            
            # otherwise add the other numbers
            for num in range(currNum, n+1):
                # add to list
                currList.append(num)
                # take this list and add more if necessary
                combRecurse(currList, num+1)
                # for backtracking remove
                currList.pop()
            
        allLists = []
        combRecurse([], 1)
        return allLists

                