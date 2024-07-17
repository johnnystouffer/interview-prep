from typing import List

"""
47. Permutations II
Difficulty -> Medium

This was the sequel to the already rather difficult Permutations
questions, what made matters worse is that the approach I had to
take was very different.

In the original I made a helper function where I made an empty
list and let the recurse stack add to it then return it. For this
one we did one permutation at a time... I will definitely visit 
this one again...

The time complexity of this will be O(n * n!) which is disgusting
cause of how brute force this is. However this is the effcient way
to do these. It is O(n * n!) because each layer in the trees
multiply by the remaining values (worst case of no duplicates) but
for each one we have to iterate through the count which (worst case)
could have no duplicates
"""

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        allPerm = [] # store all possible permutations
        currPerm = []
        count = { n:0 for n in nums }

        # store all the frequencies
        for n in nums:
            count[n] += 1

        def dfs():
            if len(currPerm) == len(nums):
                allPerm.append(currPerm.copy())
                return

            for n in count:
                if count[n] > 0:
                    currPerm.append(n)
                    count[n] -= 1

                    dfs()
                    
                    count[n] += 1
                    currPerm.pop()

        dfs()
        return allPerm
    

            



