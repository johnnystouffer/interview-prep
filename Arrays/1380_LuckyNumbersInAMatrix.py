from typing import List

"""
1380. Lucky Numbers in a Matrix

We iterate through the whole matrix and save the lowest of each
columns and max of each set the we iterate through the max and 
min lists to find if any match

The time complexity of this would be O(m*n) in both space and
time due to iterating through the entire matrix
"""

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        y_set = [float("inf")] * len(matrix)
        x_set = [0] * len(matrix[0])
        all_lucky_nums = []

        for y in range(len(matrix)):
            for x in range(len(matrix[0])):
                y_set[y] = min(y_set[y], matrix[y][x])
                x_set[x] = max(x_set[x], matrix[y][x])

        for y in range(len(matrix)):
            for x in range(len(matrix[0])):
                if y_set[y] == x_set[x]:
                    all_lucky_nums.append(matrix[y][x])

        return all_lucky_nums
        