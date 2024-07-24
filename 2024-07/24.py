# Problem: 2191. Sort the Jumbled Numbers
# Link: https://leetcode.com/problems/sort-the-jumbled-numbers/
# Beats: Runtime 1184 ms (Beats 29.89%), Memory 24.64 MB (Beats 60.87%)

# Time Complexity: O(n log n), due to the sorting operation
# Space Complexity: O(n), for storing the mapped values and indices

from typing import List

class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        # Helper function to map a number based on the given mapping
        def map_value(x):
            return int(''.join(str(mapping[int(digit)]) for digit in str(x)))
        
        # Create a list of tuples containing the mapped values, original index, and the original number
        mapped = [(map_value(x), index, x) for index, x in enumerate(nums)]
        # Sort the list based on the mapped values while maintaining the original order for equal mapped values
        mapped.sort()
        # Extract and return the sorted numbers based on their mapped values
        return [x for _, _, x in mapped]

solution = Solution()

# Example 1
mapping1 = [8, 9, 4, 0, 2, 1, 3, 5, 7, 6]
nums1 = [991, 338, 38]
print(solution.sortJumbled(mapping1, nums1))  # Output: [338, 38, 991]

# Example 2
mapping2 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
nums2 = [789, 456, 123]
print(solution.sortJumbled(mapping2, nums2))  # Output: [123, 456, 789]