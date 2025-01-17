from typing import List

"""
200. Number of Islands

Find out how many islands there are in the 
nested array, to do this we will perform a
DFS 


"""

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n, m = len(grid), len(grid[0])
        numOfIslands = 0

        # loop over nested array, performing a DFS whenever we hit
        # an island
        for y in range(n):
            for x in range(m):
                if grid[y][x] == "1":
                    numOfIslands += 1
                    self.dfs(x, y, grid)
        return numOfIslands
        
    def dfs(self, x, y, grid):
        # make sure we are in bounds
        if y < 0 or y >= len(grid) or x < 0 or x >= len(grid[y]) or grid[y][x] == "0":
            return

        # mark this as found so we don't recurse to
        # a place we already found
        grid[y][x] = "0"

        # dfs on everything next to it
        self.dfs(x+1, y, grid)
        self.dfs(x, y+1, grid)
        self.dfs(x-1, y, grid)
        self.dfs(x, y-1, grid)

        