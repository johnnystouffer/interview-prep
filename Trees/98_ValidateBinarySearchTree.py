from typing import Optional
# Definition for a binary tree node.

"""
98. Validate a Binary Tree

This one I have a commented out solution, which was my
intuitive solution of an in order traversal while keeping
track that the last one was in fact less than this current
one.

The uncommented has a different solution, this basically
takes advantage of the fact that to the left you should 
less than the current node and to the right you should be
greater than the current node, do that recursively and 
you will find the bounds and return if false
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
    #     prev, valid = [], [True]

    #     self.InOrderTraversal(root, prev, valid)
    #     return valid[0]
    
    # def InOrderTraversal(self, root: Optional[TreeNode], prev, valid):
    #     if not root:
    #         return

    #     self.InOrderTraversal(root.left, prev, valid)

    #     if len(prev) == 0 or (valid[0] and root.val > prev[-1]):
    #         prev.append(root.val)
    #     else:
    #         valid[0] = False
    #         return

    #     self.InOrderTraversal(root.right, prev, valid)

        return self.IsValid(-float("inf"), float("inf"), root)
    
    def IsValid(self, left, right, node):
        if not node:
            return True

        if node.val > left and node.val < right:
            return self.IsValid(left, node.val, node.left) and self.IsValid(node.val, right, node.right)
        else:
            return False

    

