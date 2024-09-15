# Problem: 1371. Find the Longest Substring Containing Vowels in Even Counts
# Link: https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
# Beats: 73.81% (Runtime), 33.15% (Memory)
# Time Complexity: O(n), where n is the length of the input string `s`, as we iterate through the string once.
# Space Complexity: O(1), since we are using a fixed-size array for the vowel state.

class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        """
        This function returns the length of the longest substring where all vowels ('a', 'e', 'i', 'o', 'u')
        appear an even number of times.

        :param s: Input string containing lowercase English letters.
        :return: The size of the longest substring with vowels in even counts.
        """
        # Initialize prefixXOR to track the current state of vowel counts
        prefixXOR = 0
        
        # Create a character map for vowels (a=1, e=2, i=4, o=8, u=16)
        vowel_map = [0] * 26
        vowel_map[ord('a') - ord('a')] = 1  # a is represented as 1 in binary (00001)
        vowel_map[ord('e') - ord('a')] = 2  # e is represented as 2 in binary (00010)
        vowel_map[ord('i') - ord('a')] = 4  # i is represented as 4 in binary (00100)
        vowel_map[ord('o') - ord('a')] = 8  # o is represented as 8 in binary (01000)
        vowel_map[ord('u') - ord('a')] = 16 # u is represented as 16 in binary (10000)
        
        # `state_map` keeps track of the first occurrence of each XOR state (32 possible states)
        state_map = [-1] * 32
        state_map[0] = -1  # Initial state for no vowels is at index -1
        
        longestSubstring = 0
        
        # Iterate through the string
        for i in range(len(s)):
            # XOR the current character's vowel state if it's a vowel
            prefixXOR ^= vowel_map[ord(s[i]) - ord('a')]
            
            # If we haven't seen this XOR state before, record its first occurrence
            if state_map[prefixXOR] == -1:
                state_map[prefixXOR] = i
            
            # Calculate the length of the substring from the first occurrence of this XOR state
            longestSubstring = max(longestSubstring, i - state_map[prefixXOR])
        
        return longestSubstring

# Time Complexity: O(n)
# We traverse the string `s` in a single pass, updating the XOR and calculating the length of valid substrings.

# Space Complexity: O(1)
# We use a fixed-size array `state_map` with 32 entries and a `vowel_map` with 26 entries, independent of the size of the input string.

# Test cases:
print(Solution().findTheLongestSubstring("eleetminicoworoep"))  # Expected output: 13
print(Solution().findTheLongestSubstring("leetcodeisgreat"))    # Expected output: 5
print(Solution().findTheLongestSubstring("bcbcbc"))             # Expected output: 6
