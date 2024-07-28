# Problem: 1791. Find Center of Star Graph
# Link: https://leetcode.com/problems/find-center-of-star-graph/
# Beats: Runtime 643 ms (Beats 81.42%), Memory 52.12 MB (Beats 70.88%)

# Time Complexity: O(1) - Constant time because only the first two edges are checked
# Space Complexity: O(1) - Constant space as no additional data structures are used

from typing import List

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        # Extract the nodes from the first edge
        u, v = edges[0]
        
        # Check if either of these nodes appear in the second edge
        if u in edges[1]:
            return u
        else:
            return v

# Example usage
solution = Solution()

# Example 1
edges1 = [[1, 2], [2, 3], [4, 2]]
print(solution.findCenter(edges1))  # Output: 2

# Example 2
edges2 = [[1, 2], [5, 1], [1, 3], [1, 4]]
print(solution.findCenter(edges2))  # Output: 1
