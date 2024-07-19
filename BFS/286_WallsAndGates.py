from collections import deque
from typing import List

"""
286. Walls and Gates

This needs a BFS implementation, because that way we do not go through
the entire graph for how many gates there are. cause that could end up
being very inefficient (DFS)

The time complexity for this one is O(mn) because we are iterating
through the whole list twice in the worst case scenario. the best case
which is Omega(mn) is the same so technically this is Theta(mn)
"""

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        m, n = len(rooms), len(rooms[0])
        q = deque()
        for y in range(m):
            for x in range(n):
                if rooms[y][x] == 0:
                    q.append((y, x))
        
        while q:
            y, x = q.popleft()
            for ny, nx in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
                cy, cx = y+ny, x+nx
                if (0 <= cy < m) and (0 <= cx < n) and rooms[cy][cx] == 2147483647:
                    rooms[cy][cx] = rooms[y][x] + 1
                    q.append((cy, cx))