# Problem: 214. Shortest Palindrome
# Link: https://leetcode.com/problems/shortest-palindrome/
# Beats: 52.09% (Runtime), 41.65% (Memory)
# Time Complexity: O(n^2), where n is the length of the string.
# Space Complexity: O(n), due to the space required for storing the reverse string.

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        """
        This function finds the shortest palindrome by adding characters to the front of the input string.

        :param s: A string consisting of lowercase English letters.
        :return: The shortest palindrome that can be obtained by adding characters in front of the string.
        """
        n = len(s)
        reverse_s = s[::-1]  # Reverse the string
        
        # Try different lengths to find the largest prefix of s that is also a suffix in the reversed string
        for i in range(n):
            # Check if s[:n-i] is a palindrome by comparing with reverse_s[i:]
            if s[:n-i] == reverse_s[i:]:
                # Return the shortest palindrome by adding reverse_s[:i] at the beginning of s
                return reverse_s[:i] + s
        
        # If no prefix-suffix match is found, return an empty string
        return ""

# Time Complexity:
# O(n^2) - We check for each prefix of the string if it's a palindrome, requiring linear time for each check and quadratic time overall.

# Space Complexity:
# O(n) - We use space to store the reversed version of the string.

# Example test cases:
print(Solution().shortestPalindrome("aacecaaa"))  # Expected output: "aaacecaaa"
print(Solution().shortestPalindrome("abcd"))      # Expected output: "dcbabcd"
