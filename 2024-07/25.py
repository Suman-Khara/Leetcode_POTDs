# Problem: 912. Sort an Array
# Link: https://leetcode.com/problems/sort-an-array/
# Beats: Runtime 545 ms (Beats 90.23%), Memory 26.55 MB (Beats 21.89%)

# Time Complexity: O(n + k), where n is the number of elements in the array and k is the range of the input
# Space Complexity: O(k), for the frequency array

from typing import List

class Solution:
    # Counting Sort algorithm
    def countingSort(self, nums: List[int]) -> List[int]:
        # Find the minimum and maximum values in the array
        low, high = min(nums), max(nums)
        # Create a frequency array to count the occurrences of each number
        freq = [0] * (high - low + 1)
        
        # Count the frequency of each number in the array
        for num in nums:
            freq[num - low] += 1
        
        # Create the sorted array using the frequency array
        sorted_nums = []
        for index, count in enumerate(freq):
            sorted_nums.extend([index + low] * count)
        
        return sorted_nums

    # Main function to sort the array
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.countingSort(nums)

# Example Usage
solution = Solution()

# Example 1
nums1 = [5, 2, 3, 1]
print(solution.sortArray(nums1))  # Output: [1, 2, 3, 5]

# Example 2
nums2 = [5, 1, 1, 2, 0, 0]
print(solution.sortArray(nums2))  # Output: [0, 0, 1, 1, 2, 5]
