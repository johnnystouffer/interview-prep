from typing import List

"""
695. Max Area of an Island

Another DFS problem where we iterate through
the entire nested list finding 1s and then
calculating the area of the island. 
"""

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        if len(grid) == 0:
            return 0

        max_num = 0
        n, m = len(grid), len(grid[0])

        for y in range(n):
            for x in range(m):
                if grid[y][x] == 1:
                    max_num = max(max_num, self.dfs(x, y, grid))
        return max_num

    def dfs(self, x, y, grid) -> int:
        if y < 0 or y >= len(grid) or x < 0 or x >= len(grid[y]) or grid[y][x] == 0:
            return 0

        grid[y][x] = 0

        return 1 + self.dfs(x+1, y, grid) + self.dfs(x, y+1, grid) + self.dfs(x-1, y, grid) + self.dfs(x, y-1, grid)