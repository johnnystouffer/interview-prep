from typing import Optional

"""
110. Balanced Binary Tree

Simple process here, we want to calculate
the height of every node and then calculate
the difference in l vs r. Determine based
on there
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
       
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        ans = [True]

        self.height(root, ans)

        return ans[0]

    def height(self, root, ans):
        if not root:
            return 0
        
        l = self.height(root.left, ans) + 1
        r = self.height(root.right, ans) + 1

        if abs(l - r) > 1:
            ans[0] = False

        return max(l, r)
        

        