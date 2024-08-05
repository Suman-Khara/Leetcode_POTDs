# Problem: 2053. Kth Distinct String in an Array
# Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/
# Runtime: 65 ms (Beats 81.26%)
# Memory: 16.82 MB (Beats 35.47%)
# Time Complexity: O(n), where n is the length of the array
# Space Complexity: O(n), for storing the frequency count of each string

from typing import List

class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        # Dictionary to store the frequency of each string
        frequency = {}
        
        # Iterate through the array to count the occurrences of each string
        for string in arr:
            if string in frequency:
                frequency[string] += 1
            else:
                frequency[string] = 1
        
        # Iterate through the array to find the kth distinct string
        for string in arr:
            if frequency[string] == 1:
                k -= 1
                # If k reaches 0, return the current string as the kth distinct string
                if k == 0:
                    return string
        
        # If there are fewer than k distinct strings, return an empty string
        return ""

# Example 1
arr1 = ["d", "b", "c", "b", "c", "a"]
k1 = 2
print(Solution().kthDistinct(arr1, k1))  # Output: "a"

# Example 2
arr2 = ["aaa", "aa", "a"]
k2 = 1
print(Solution().kthDistinct(arr2, k2))  # Output: "aaa"

# Example 3
arr3 = ["a", "b", "a"]
k3 = 3
print(Solution().kthDistinct(arr3, k3))  # Output: ""
