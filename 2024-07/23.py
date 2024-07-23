# Problem: 1636. Sort Array by Increasing Frequency
# Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/
# Beats: Runtime 56 ms (Beats 19.25%), Memory 16.43 MB (Beats 76.93%)

# Time Complexity: O(n log n), due to the sorting operation
# Space Complexity: O(n), for storing the frequency counter

from typing import List
from collections import Counter

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        # Create a frequency counter for the elements in nums
        frequency = Counter(nums)
        # Sort nums based on the frequency of each element, and by value in decreasing order for ties
        nums.sort(key=lambda x: (frequency[x], -x))
        return nums

# Example Usage
solution = Solution()

# Example 1
nums1 = [1, 1, 2, 2, 2, 3]
print(solution.frequencySort(nums1))  # Output: [3, 1, 1, 2, 2, 2]

# Example 2
nums2 = [2, 3, 1, 3, 2]
print(solution.frequencySort(nums2))  # Output: [1, 3, 3, 2, 2]

# Example 3
nums3 = [-1, 1, -6, 4, 5, -6, 1, 4, 1]
print(solution.frequencySort(nums3))  # Output: [5, -1, 4, 4, -6, -6, 1, 1, 1]
