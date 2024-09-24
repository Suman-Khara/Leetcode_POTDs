# Problem: 3043. Find the Length of the Longest Common Prefix
# Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
# Beats: 93.10% (Runtime), 51.33% (Memory)
# Time Complexity: O(n log n + m), where n is the total number of elements in arr1 and arr2, 
#                  and m is the sum of the lengths of all elements when converted to strings.
# Space Complexity: O(n), due to the additional space needed for the string representations of the numbers.

from typing import List

class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        """
        This function finds the length of the longest common prefix between any two integers,
        one from arr1 and one from arr2.

        :param arr1: A list of integers.
        :param arr2: A list of integers.
        :return: The length of the longest common prefix among all pairs.
        """
        arr = []
        
        # Append the numbers from arr1 with an 'x' marker and from arr2 with a 'y' marker.
        for i in arr1:
            arr.append(str(i) + 'x')
        for i in arr2:
            arr.append(str(i) + 'y')
        
        # Sort the array lexicographically. This will put the similar prefixes together.
        arr.sort()
        
        # Helper function to calculate the common prefix length between two strings
        def prefix(s1, s2):
            n = min(len(s1), len(s2))
            ans = 0
            for i in range(n):
                if s1[i] == s2[i]:
                    ans += 1
                else:
                    break
            return ans
        
        n = len(arr)
        longest_common_prefix_length = 0
        
        # Iterate through the sorted array, and compare consecutive elements that belong to different arrays (x and y).
        for i in range(1, n):
            if arr[i][-1] != arr[i - 1][-1]:  # Check that the last character (marker) is different
                longest_common_prefix_length = max(longest_common_prefix_length, prefix(arr[i], arr[i - 1]))
        
        return longest_common_prefix_length

# Time Complexity:
# O(n log n + m), where n is the combined length of arr1 and arr2 and m is the total number of digits of all integers.
# Sorting takes O(n log n), and the prefix function runs in O(m).

# Space Complexity:
# O(n) - Extra space is needed for the string representation of numbers and the sorted list.

# Example test cases:
print(Solution().longestCommonPrefix([1, 10, 100], [1000]))  # Expected output: 3
print(Solution().longestCommonPrefix([1, 2, 3], [4, 4, 4]))  # Expected output: 0
