from collections import deque
from typing import List

"""
994. Rotten Oranges
Difficulty -> Medium

This one goes from
"""

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        if not grid:
            return -1
            
        how_many_min = 0
        q = deque()
        m, n = len(grid), len(grid[0])
        fresh_oranges = 0
        for y in range(m):
            for x in range(n):
                if grid[y][x] == 2:
                    q.append((0, y, x))
                elif grid[y][x] == 1:
                    fresh_oranges += 1
                    
        if fresh_oranges == 0:
            return 0

        directions = ((1, 0), (0, 1), (-1, 0), (0, -1))

        while q:
            mint, y, x = q.popleft()
            for ny, nx in directions:
                cy, cx = y+ny, x+nx
                if 0 <= cy < m and 0 <= cx < n and grid[cy][cx] == 1:
                    grid[cy][cx] = 2
                    fresh_oranges -= 1
                    q.append((mint+1, cy, cx))
                    how_many_min = max(how_many_min, mint + 1)

        if fresh_oranges > 0:
            return -1
        
        return how_many_min


        