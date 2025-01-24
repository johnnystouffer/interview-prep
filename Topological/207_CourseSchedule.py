from collections import deque
from typing import List

"""
207. Course Schedule
Difficulty -> Medium

This is THE topological course question basically, we see all the incoming
edges of each node, then we start with the node with zero incoming edges
then removing what they point to specifically, until we have reached all
nodes, then will terminate if there is a cycle or not.

The time complexity is O(V + E) as we iterate through all known Edges E and
nodes (vertices) V. This will technically be Theta(V+E) because in the best
case we also run it in V+E time. 
"""

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites:
            return True

        # add all courses and all of their dependencies
        courseMap = {i: [] for i in range(numCourses)}
        inMap = {i: 0 for i in range(numCourses)}
        
        for post, pre in prerequisites:
            courseMap[pre].append(post)
            inMap[post] += 1
            
        q = deque([u for u in inMap if inMap[u] == 0])
        finalOrder = set()

        while q:
            curr = q.popleft()
            finalOrder.add(curr)

            for neighbor in courseMap[curr]:
                inMap[neighbor] -= 1
                if inMap[neighbor] == 0:
                    q.append(neighbor)

        return len(finalOrder) == numCourses


"""
RETRY:

After not being on leetcode for a millenium it feels like, I am back and I have
attempted this problem again... And I shit you not it looks the EXACT SAME

The only difference I want to point out is that my variable names this time around
look significantly better than before, thank you.
"""


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if not prerequisites:
            return True

        # make a dictionary for the number of prereqs left for this course
        numPrereq = {i: 0 for i in range(numCourses)}
        # make a dictionary for all the classes this one is a prereq for
        nextCourses = {i: [] for i in range(numCourses)}

        for post, pre in prerequisites:
            # add a prereq and add it to the list for pre
            numPrereq[post] += 1
            nextCourses[pre].append(post)

        q = deque([i for i in numPrereq if numPrereq[i] == 0])
        finalOrder = set()
        
        while q:
            value = q.popleft()
            finalOrder.add(value)

            for nextClass in nextCourses[value]:
                numPrereq[nextClass] -= 1
                if numPrereq[nextClass] == 0:
                    q.append(nextClass)
        
        return len(finalOrder) == numCourses