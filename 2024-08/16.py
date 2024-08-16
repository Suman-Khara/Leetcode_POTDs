# Problem: 624. Maximum Distance in Arrays
# Link: https://leetcode.com/problems/maximum-distance-in-arrays/
# Beats: 39.94% (Runtime: 1358 ms), 51.44% (Memory: 42.52 MB)
# Time Complexity: O(m) - The algorithm processes each of the m arrays once.
# Space Complexity: O(1) - The space used is constant.

from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        # Initialize minimum and maximum values from the first array
        min_val = arrays[0][0]
        max_val = arrays[0][-1]
        max_distance = 0
        
        # Iterate over the remaining arrays
        for array in arrays[1:]:
            # Calculate the possible maximum distances using the current array
            max_distance = max(max_distance, abs(array[-1] - min_val), abs(max_val - array[0]))
            # Update min_val and max_val to include the current array
            min_val = min(min_val, array[0])
            max_val = max(max_val, array[-1])
        
        return max_distance

# Example usage:
solution = Solution()

# Test case 1
arrays1 = [[1, 2, 3], [4, 5], [1, 2, 3]]
print(solution.maxDistance(arrays1))  # Output: 4

# Test case 2
arrays2 = [[1], [1]]
print(solution.maxDistance(arrays2))  # Output: 0
