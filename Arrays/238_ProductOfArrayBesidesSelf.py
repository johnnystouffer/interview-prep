from typing import List

"""
238. Product of Array Besides itself

This question wants us to make a second array (or in place if
you want to) where you find the product of all positions besides
this current position

For this question the most optimal solution is O(n) and O(1) space
and it is Prefix Sum. Basically we go through array front and back
and through that we multiply those two together... its confusing read my comments
"""

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # # create two lists, one for prefix and one for post
        # prefix, postfix = [nums[0]], [nums[len(nums) - 1]]

        # # we loop through the list, multiplying each number we reach
        # # and add it to the list
        # for i in range(1, len(nums)):
        #     newPre = prefix[i-1] * nums[i]
        #     prefix.append(newPre)
        #     newPost = postfix[i-1] * nums[len(nums)-1-i]
        #     postfix.append(newPost)

        # # next we take the pre and post of each i-1 and i+1, multiply
        # # them together
        # ans = []
        # for i in range(len(nums)):
        #     edit = 1
        #     if i >= 1:
        #         edit *= prefix[i-1]
        #     if i < len(nums) - 1:
        #         edit *= postfix[len(nums)-2-i]
        #     ans.append(edit)
        #
        # return ans

        ans = [1] * len(nums)

        prefix = 1
        for i in range(len(nums)):
            ans[i] *= prefix
            prefix *= nums[i]

        postfix = 1
        for i in range(len(nums)-1, -1, -1):
            ans[i] *= postfix
            postfix *= nums[i]

        return ans
