import heapq
from typing import List

"""
1514. Path With Maximum Probability
Difficulty -> Medium

We will use dijkstras algo to go through the graph
as and track the probabilities

this will have a time complexity of O((V+E)logV)
"""

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        
        # saying if either are in valid we cannot do it
        if not (0 <= end_node < n) or not (0 <= start_node < n):
            return 0.0

        # making an adjacency list and tracking the shortest
        shortest = dict()
        adj = dict()

        # adding all nodes to the adjacency list
        for i in range(n):
            adj[i] = []

        # adding all edges they are adjacent to
        for i in range(len(edges)):
            src, dest = edges[i]
            adj[src].append((dest, succProb[i]))
            adj[dest].append((src, succProb[i]))

        # make our heap to start out
        heap = [(-1, start_node)]
        while heap:
            weight1, node = heapq.heappop(heap)
            if node in shortest:
                continue
            shortest[node] = -(weight1)

            if node == end_node:
                return -weight1

            for dest, weight2 in adj[node]:
                if dest not in shortest:
                    heapq.heappush(heap, (weight1*weight2, dest))

        if end_node in shortest:
            return shortest[end_node] 
        else:
            return 0.0

        
        

