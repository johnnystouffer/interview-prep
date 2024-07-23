from collections import deque
from typing import List

"""
210. Course Schedule II
Difficulty -> Medium

Same as course schedule one in terms of basically everything so look there
for advice on this one. The only difference is that this time we return the
courses and not just a boolean (also they swapped the prereq positions)
"""

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        finalList = []

        if not prerequisites:
            return [i for i in range(numCourses)]

        courseMap = {i: [] for i in range(numCourses)}
        inMap = {i: 0 for i in range(numCourses)}

        for post, pre in prerequisites:
            courseMap[pre].append(post)
            inMap[post] += 1

        q = deque([i for i in inMap.keys() if inMap[i] == 0])

        while q:
            curr = q.popleft()
            finalList.append(curr)

            for n in courseMap[curr]:
                inMap[n] -= 1
                if inMap[n] == 0:
                    q.append(n)

        return [] if len(finalList) != numCourses else finalList
