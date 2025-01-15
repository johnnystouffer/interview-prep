from typing import Optional

"""
226. Invert a Binary Tree

Poor homebrew creator... basically instead
of the left sight being greater the right side
should be greater, basically inverting every
nodes children, which is all the code does, 
this is also O(n) since it runs through all the
nodes.
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return
        root.left, root.right = root.right, root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root