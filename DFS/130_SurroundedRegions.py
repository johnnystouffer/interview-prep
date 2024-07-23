from typing import List

"""
130 - Surrounded Regions
Difficulty -> Medium

This one we have to go through all the edges if it is
an O then mark all connected ones.
"""

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def inBounds(y, x):

            if x < 0 or y < 0:
                return False
            if x >= len(board[0]) or y >= len(board):
                return False
            return True


        def dfs(y, x):

            if not inBounds(y, x) or board[y][x] != 'O':
                return
            
            board[y][x] = 'G'
            for ny, nx in directions:
                dfs(y+ny, x+nx)
                

            
            
        directions = [(1,0), (0,1), (-1,0), (0,-1)]
        visited = set()
        for y in range(len(board)):
            for x in range(len(board[0])):
                if (x == 0 or x == len(board[0])-1 or y == 0 or y == len(board)-1) and board[y][x] == 'O':
                    dfs(y, x)
        
        for y in range(len(board)):
            for x in range(len(board[0])):
                if board[y][x] == 'O':
                    board[y][x] = 'X'
                    continue
                if board[y][x] == 'G':
                    board[y][x] = 'O'
        
            

        