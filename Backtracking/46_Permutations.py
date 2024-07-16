from typing import List

"""
46. Permuations
Difficulty -> Medium

This one was more explicit on what to do. You need to find
the permutations of the list. We can find this by going all
the way through the recurse stack and return an empty list, 
fromt there you make copies and add each given one, then do
this all the way up the stack

Incredibly inefficient though as this will run at O(n^2 * n!)
where n is the length of nums, as we are doing a nested for
loop plus the recursion would be n! as we go a level per num
"""

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return self.recurse(nums, 0)
    
    def recurse(self, nums, i):
        if len(nums) == i:
            return [[]]

        allPerms = []
        perms = self.recurse(nums, i+1)
        for p in perms:
            for j in range(len(p)+1):
                p2 = p.copy()
                p2.insert(j, nums[i])
                allPerms.append(p2)

        return allPerms


            