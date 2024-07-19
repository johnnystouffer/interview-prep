from typing import List

"""
200. Number of Islands

We can use DFS when we reach each island.

O(E + V) because for the worst case is one island is the whole
graph
"""

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        numberOfIslands = 0
        for y in range(len(grid)):
            for x in range(len(grid[0])):
                if grid[y][x] == "1":
                    numberOfIslands +=1 
                    self.dfs(y, x, grid)
        return numberOfIslands
    
    def dfs(self, y, x, grid):
        if y >= len(grid) or x >= len(grid[0]) or x < 0 or y < 0 or grid[y][x] == "0":
            return
        grid[y][x] = "0"
        self.dfs(y+1, x, grid)       
        self.dfs(y, x+1, grid)       
        self.dfs(y-1, x, grid)       
        self.dfs(y, x-1, grid)
        return       
    
    