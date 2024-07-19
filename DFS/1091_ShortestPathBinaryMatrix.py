from collections import deque
from typing import List

"""
1091. Shortest Path in Binary Matrix
Difficulty -> Medium

This uses DFS to go through the graph, we do this in all directions
but the efficiency will not go down because we mark them visited.

the time complexity will be O(E+V)
"""

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        # If the start or end cell is blocked, return -1
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        
        n = len(grid)
        directions = [
            (1, 0), (0, 1), (1, 1), (-1, 0),
            (1, -1), (-1, 1), (-1, -1), (0, -1)
        ]
        
        q = deque([(0, 0, 1)])  # (y, x, path length)
        grid[0][0] = 1  # Mark the start cell as visited by using any non-zero number

        while q:
            y, x, length = q.popleft()
            
            # If we have reached the bottom-right cell
            if y == n - 1 and x == n - 1:
                return length
            
            for dy, dx in directions:
                ny, nx = y + dy, x + dx
                if 0 <= ny < n and 0 <= nx < n and grid[ny][nx] == 0:
                    q.append((ny, nx, length + 1))
                    grid[ny][nx] = 1  # Mark as visited
        
        return -1  # No path found
