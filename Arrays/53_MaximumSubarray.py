from typing import List

"""
53. Maximum Subarray

KADANES ALGORITHM!! A greedy dynamic algorithm that can be used
on an array to calculate the maximum sum subarray ending at
a particular position and typically runs in O(n)

This algorithm makes it so you do not need to run through every
possible sub array to find the max because of two reasons:

1. If the whole array is positive then the largest subarray
is the whole array

2. If we ever reach negative then it makes more sense to start
over instead of trying to keep adding on.
"""

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        currSum = 0

        for n in nums:
            # if we reach negative then we move on :'(
            currSum = currSum if currSum > 0 else 0
            currSum += n
            maxSum = max(maxSum, currSum)
        return maxSum