# Problem: 884. Uncommon Words from Two Sentences
# Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/
# Beats: 91.55% (Runtime), 44.21% (Memory)
# Time Complexity: O(n), where n is the total number of words in both sentences combined.
# Space Complexity: O(n), as we store the words and their frequencies in a dictionary.

from collections import Counter
from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        """
        This function returns a list of words that appear exactly once in one of the two given sentences (s1, s2)
        and do not appear in the other sentence.

        :param s1: First sentence as a string.
        :param s2: Second sentence as a string.
        :return: A list of uncommon words between s1 and s2.
        """
        # Concatenate both sentences with a space in between
        combined_sentences = s1 + " " + s2
        
        # Split the combined string into individual words
        words = combined_sentences.split()
        
        # Count the frequency of each word using Counter
        word_count = Counter(words)
        
        # Return words that appear exactly once (freq == 1)
        return [word for word, freq in word_count.items() if freq == 1]

# Time Complexity: O(n)
# We iterate through the concatenated sentence to split the words and count their occurrences, which is O(n), where n is the total number of words.

# Space Complexity: O(n)
# We store all the words and their frequencies in the Counter dictionary, which requires O(n) space.

# Example test cases:
print(Solution().uncommonFromSentences("this apple is sweet", "this apple is sour"))  # Expected output: ["sweet","sour"]
print(Solution().uncommonFromSentences("apple apple", "banana"))                     # Expected output: ["banana"]