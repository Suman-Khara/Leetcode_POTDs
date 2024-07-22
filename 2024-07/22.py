# Problem: 2418. Sort the People
# Link: https://leetcode.com/problems/sort-the-people/
# Beats: Runtime 112 ms (Beats 35.58%), Memory 16.98 MB (Beats 84.16%)

# Time Complexity: O(n log n), due to the sorting operation
# Space Complexity: O(n), for storing the sorted list

from typing import List

class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        # Combine names and heights into a list of tuples, and sort by height in descending order
        sorted_people = sorted(zip(heights, names), reverse=True)
        # Extract and return the names from the sorted list of tuples
        return [name for height, name in sorted_people]

solution = Solution()

# Example 1
names1 = ["Mary", "John", "Emma"]
heights1 = [180, 165, 170]
print(solution.sortPeople(names1, heights1))  # Output: ["Mary", "Emma", "John"]

# Example 2
names2 = ["Alice", "Bob", "Bob"]
heights2 = [155, 185, 150]
print(solution.sortPeople(names2, heights2))  # Output: ["Bob", "Alice", "Bob"]
