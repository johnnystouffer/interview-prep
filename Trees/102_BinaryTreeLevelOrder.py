from collections import deque
from typing import List, Optional
# Definition for a binary tree node.

# tree node class for the problem
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # EDGE CASE no root actually given
        if not root:
            return []

        # make a queue and add our root
        q = deque()
        q.append((root, 0))
        currIter = -1
        listOfNodes = []

        while q:
            # get the node from the front of the queue
            currNode, level = q.popleft()

            # see of we got to a new level
            # if so then add the new list to listOfNodes
            if currIter < level:
                listOfNodes.append([])
                currIter = level

            # add this node to its levels list
            listOfNodes[-1].append(currNode.val)

            # add the left and right children to the queue and one level down
            if currNode.left:
                q.append((currNode.left, level+1))
            if currNode.right:
                q.append((currNode.right, level+1))

        # return all the nodes that are given
        return listOfNodes
    

"""
Attempt 2:

Pretty similar to the first attempt thankfully
Other than that I am glad to report that all is
good for me right now
"""
from typing import Optional, List
from collections import deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        q = deque()
        q.append((root, 0))


        currLevel = -1
        finalList = []
        while q:
            currNode, level = q.popleft()
            if level > currLevel:
                finalList.append([])
                currLevel = level

            finalList[-1].append(currNode.val)

            if currNode.left:
                q.append((currNode.left, level+1))
            if currNode.right:
                q.append((currNode.right, level+1))

        return finalList

            

            
            

