# Problem: 2416. Sum of Prefix Scores of Strings
# Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/
# Beats: 49.31% (Runtime), 70.34% (Memory)
# Time Complexity: O(N * L), where N is the number of words and L is the maximum length of a word. 
#                  Each word is inserted into the Trie and then scored, taking O(L) time for both operations.
# Space Complexity: O(N * L), as we store all characters of the words in the Trie, 
#                   leading to potentially storing all characters from all words.

class TrieNode:
    def __init__(self):
        # Dictionary to hold child nodes for each character
        self.children = {}
        # Count of how many words share the prefix represented by this node
        self.count = 0  

class Trie:
    def __init__(self):
        # Root node of the Trie
        self.root = TrieNode()

    def insert(self, word):
        # Insert a word into the Trie and update prefix counts
        current_node = self.root
        for char in word:
            # If character not present, create a new TrieNode
            if char not in current_node.children:
                current_node.children[char] = TrieNode()
            # Move to the child node
            current_node = current_node.children[char]
            # Increment the count of words passing through this node
            current_node.count += 1  

    def get_prefix_score(self, word):
        # Calculate the total score for all prefixes of the given word
        current_node = self.root
        total_score = 0
        for char in word:
            # Move to the child node corresponding to the character
            if char in current_node.children:
                current_node = current_node.children[char]
                # Add the count of words sharing this prefix to the score
                total_score += current_node.count  
        return total_score

class Solution:
    def sumPrefixScores(self, words):
        # Create a Trie to store all words and their prefix scores
        trie = Trie()
        
        # Insert each word into the Trie
        for word in words:
            trie.insert(word)
        
        # List to store the total prefix scores for each word
        scores = []
        for word in words:
            # Get the prefix score for the current word and append it to the scores list
            scores.append(trie.get_prefix_score(word))
        
        return scores

# Example test cases
print(Solution().sumPrefixScores(["abc", "ab", "bc", "b"]))  # Expected output: [5, 4, 3, 2]
print(Solution().sumPrefixScores(["abcd"]))  # Expected output: [4]
