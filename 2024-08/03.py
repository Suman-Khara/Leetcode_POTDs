# Problem: 1460. Make Two Arrays Equal by Reversing Subarrays
# Link: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
# Beats: 51.41%

# Time Complexity: O(n log n)
# Space Complexity: O(n)

from typing import List

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        # Check if sorted versions of both arrays are equal
        # If they are, it means arr can be rearranged to match target
        return sorted(target) == sorted(arr)

# Example 1
target = [1, 2, 3, 4]
arr = [2, 4, 1, 3]
print(Solution().canBeEqual(target, arr))  # Output: True

# Example 2
target = [7]
arr = [7]
print(Solution().canBeEqual(target, arr))  # Output: True

# Example 3
target = [3, 7, 9]
arr = [3, 7, 11]
print(Solution().canBeEqual(target, arr))  # Output: False
