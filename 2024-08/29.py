# Problem: 947. Most Stones Removed with Same Row or Column
# Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
# Beats: 50.08% (Runtime), 36.94% (Memory)
# Time Complexity: O(n * α(n)) where n is the number of stones, and α(n) is the inverse Ackermann function, which is very slow-growing and almost constant.
# Space Complexity: O(n) for the DSU structure storing parent and size arrays.

from typing import List

class DisjointSetUnion:
    def __init__(self, n):
        # Initialize size and parent arrays for DSU
        self.size = [1] * (n + 1)
        self.parent = list(range(n + 1))

    def find(self, x):
        # Path compression to find the root parent of x
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, u, v):
        # Union by size: attach the smaller tree under the larger tree
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u == root_v:
            return
        if self.size[root_u] < self.size[root_v]:
            self.parent[root_u] = root_v
            self.size[root_v] += self.size[root_u]
        else:
            self.parent[root_v] = root_u
            self.size[root_u] += self.size[root_v]

class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        # Calculate the max rows and columns needed
        max_row = max(stone[0] for stone in stones)
        max_col = max(stone[1] for stone in stones)
        
        # Initialize DSU for the total number of unique rows and columns
        dsu = DisjointSetUnion(max_row + max_col + 2)

        # Union stones by their rows and columns
        for row, col in stones:
            dsu.union(row, max_row + col + 1)

        # Use a set to count unique root parents
        unique_roots = set()
        for row, col in stones:
            unique_roots.add(dsu.find(row))

        # The answer is the total number of stones minus the number of unique components
        return len(stones) - len(unique_roots)

# Example usage:
solution = Solution()

# Test case 1
stones1 = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
print(solution.removeStones(stones1))  # Output: 5

# Test case 2
stones2 = [[0,0],[0,2],[1,1],[2,0],[2,2]]
print(solution.removeStones(stones2))  # Output: 3

# Test case 3
stones3 = [[0,0]]
print(solution.removeStones(stones3))  # Output: 0
