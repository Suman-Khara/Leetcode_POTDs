# Problem: 1514. Path with Maximum Probability
# Link: https://leetcode.com/problems/path-with-maximum-probability/
# Beats: 68.23% (Runtime), 69.45% (Memory)
# Time Complexity: O((E + V) log V), where E is the number of edges and V is the number of vertices.
# Space Complexity: O(E + V) for storing the graph and priority queue.

import heapq
from typing import List

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        # Create the graph as an adjacency list where each node points to its neighbors and the associated probability.
        graph = [[] for _ in range(n)]
        for (u, v), p in zip(edges, succProb):
            graph[u].append((v, p))
            graph[v].append((u, p))
        
        # This list holds the maximum probability to reach each node starting from the 'start' node.
        max_prob = [0.0] * n
        max_prob[start] = 1.0
        
        # Priority queue to explore nodes. We store negative probabilities to simulate a max-heap using Python's min-heap.
        pq = [(-max_prob[start], start)]
        
        while pq:
            # Get the node with the highest current probability.
            curr_prob, node = heapq.heappop(pq)
            curr_prob = -curr_prob  # Convert back to positive probability.
            
            # If this probability is less than the recorded max probability, skip further processing.
            if curr_prob < max_prob[node]:
                continue
            
            # Explore the neighbors of the current node.
            for neighbor, edge_prob in graph[node]:
                # Calculate the new probability for the neighbor node.
                new_prob = curr_prob * edge_prob
                
                # If the new probability is greater than the recorded probability, update it.
                if max_prob[neighbor] < new_prob:
                    max_prob[neighbor] = new_prob
                    # Push the neighbor into the priority queue with the new probability.
                    heapq.heappush(pq, (-new_prob, neighbor))
        
        # The result is the maximum probability to reach the 'end' node. If no path exists, it remains 0.
        return max_prob[end]

# Example usage:
solution = Solution()

# Test case 1
n1 = 3
edges1 = [[0,1],[1,2],[0,2]]
succProb1 = [0.5, 0.5, 0.2]
start1 = 0
end1 = 2
print(solution.maxProbability(n1, edges1, succProb1, start1, end1))  # Output: 0.25000

# Test case 2
n2 = 3
edges2 = [[0,1],[1,2],[0,2]]
succProb2 = [0.5, 0.5, 0.3]
start2 = 0
end2 = 2
print(solution.maxProbability(n2, edges2, succProb2, start2, end2))  # Output: 0.30000

# Test case 3
n3 = 3
edges3 = [[0,1]]
succProb3 = [0.5]
start3 = 0
end3 = 2
print(solution.maxProbability(n3, edges3, succProb3, start3, end3))  # Output: 0.00000
