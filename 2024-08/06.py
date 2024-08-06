# Problem: 3016. Minimum Number of Pushes to Type Word II
# Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
# Runtime: 238 ms (Beats 18.14%)
# Memory: 17.72 MB (Beats 8.11%)
# Time Complexity: O(n log n), where n is the length of the word (due to sorting)
# Space Complexity: O(1), assuming the alphabet size is constant (26 letters)

from collections import Counter

class Solution:
    def minimumPushes(self, word: str) -> int:
        # Count frequency of each letter in the word
        frequency = Counter(word)
        
        # Sort letters by frequency in descending order
        sorted_letters = sorted(frequency.items(), key=lambda x: x[1], reverse=True)
        
        # Initialize push costs for each letter based on its rank
        push_cost = {}
        for i, (letter, freq) in enumerate(sorted_letters):
            if i < 8:
                push_cost[letter] = 1
            elif i < 16:
                push_cost[letter] = 2
            elif i < 24:
                push_cost[letter] = 3
            else:
                push_cost[letter] = 4
        
        # Calculate the total number of pushes required
        total_pushes = 0
        for letter in word:
            total_pushes += push_cost[letter]
        
        return total_pushes

# Example 1
word1 = "abcde"
print(Solution().minimumPushes(word1))  # Output: 5

# Example 2
word2 = "xyzxyzxyzxyz"
print(Solution().minimumPushes(word2))  # Output: 12

# Example 3
word3 = "aabbccddeeffgghhiiiiii"
print(Solution().minimumPushes(word3))  # Output: 24
