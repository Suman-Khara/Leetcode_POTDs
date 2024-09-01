# Problem: 2022. Convert 1D Array Into 2D Array
# Link: https://leetcode.com/problems/convert-1d-array-into-2d-array/
# Beats: 89.74% (Runtime), 79.94% (Memory)
# Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
# Space Complexity: O(m * n) for the resulting 2D array.

from typing import List

class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        # Check if it is possible to convert the 1D array into the desired 2D array with m rows and n columns.
        if len(original) != m * n:
            return []
        
        # Initialize an empty list to store the result.
        result = []
        
        # Iterate through the original list in chunks of size n and add each chunk as a row in the 2D array.
        for i in range(m):
            row = original[i * n:(i + 1) * n]
            result.append(row)
        
        return result

# Example usage:
solution = Solution()

# Test case 1
original1 = [1, 2, 3, 4]
m1 = 2
n1 = 2
print(solution.construct2DArray(original1, m1, n1))  # Output: [[1, 2], [3, 4]]

# Test case 2
original2 = [1, 2, 3]
m2 = 1
n2 = 3
print(solution.construct2DArray(original2, m2, n2))  # Output: [[1, 2, 3]]

# Test case 3
original3 = [1, 2]
m3 = 1
n3 = 1
print(solution.construct2DArray(original3, m3, n3))  # Output: []

# Test case 4 (custom)
original4 = [1, 2, 3, 4, 5, 6]
m4 = 2
n4 = 3
print(solution.construct2DArray(original4, m4, n4))  # Output: [[1, 2, 3], [4, 5, 6]]

# Test case 5 (custom)
original5 = [1]
m5 = 1
n5 = 1
print(solution.construct2DArray(original5, m5, n5))  # Output: [[1]]
