# Problem: 2220. Minimum Bit Flips to Convert Number
# Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
# Beats: 7.58% (Runtime), 26.96% (Memory)
# Time Complexity: O(log(max(start, goal))), since computing the XOR and counting the 1's involves traversing the bits of the input numbers.
# Space Complexity: O(1), since we are using constant extra space for variables.

class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        """
        Computes the minimum number of bit flips required to convert start to goal.

        :param start: The starting integer.
        :param goal: The target integer.
        :return: The minimum number of bit flips required.
        """
        # XOR of start and goal will highlight the positions of differing bits as 1.
        xor_result = start ^ goal
        
        # Count the number of 1's in the XOR result, which corresponds to the number of bit flips needed.
        bit_flips = bin(xor_result).count('1')
        
        return bit_flips

# Time Complexity: O(log(max(start, goal)))
# The XOR operation takes O(log(max(start, goal))) time, where the number of bits depends on the larger of start or goal.
# The count operation counts the number of '1' bits, which also takes O(log(max(start, goal))).

# Space Complexity: O(1)
# We are using a constant amount of space, only storing the result of XOR and a few variables.

# Test cases:
print(Solution().minBitFlips(10, 7))  # Expected output: 3
print(Solution().minBitFlips(3, 4))   # Expected output: 3
