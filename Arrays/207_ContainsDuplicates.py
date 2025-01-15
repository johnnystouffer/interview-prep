from typing import List

"""
217. Contains Duplicates

This one is simple. You want to see if the array has any duplicates. 
There is a very easy way to do this, it is slightly less efficient
then the easy way

the length of a set and the length of the array is the same if no duplicates
which is what you can see in the comment

However that will make us iterate through the whole array everytime, so in
time complexity they both are O(n), the uncommented which stores everything
that we have seen until we hit a repeat, will make less computations since
it can end mid way through the list
"""

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # return len(set(nums)) != len(nums)
        has = {}
        for i in nums:
            if i in has:
                return True
            has[i] = i
        return False