# Problem: 476. Number Complement
# Link: https://leetcode.com/problems/number-complement/
# Beats: 9.65% (Runtime: 42 ms), 89.59% (Memory: 16.37 MB)
# Time Complexity: O(1) - The algorithm uses a constant number of operations.
# Space Complexity: O(1) - The space used is constant.

class Solution:
    def findComplement(self, num: int) -> int:
        # Special case: if the number is 0, its complement should be 1
        if num == 0:
            return 1
        
        # Find the number of bits required to represent the number in binary
        bit_length = num.bit_length()
        
        # Create a mask with all bits set to 1 of the same length as num
        # For example, if num is 5 (101 in binary), bit_length is 3,
        # so mask will be 111 (binary), which is 7 in decimal.
        mask = (1 << bit_length) - 1
        
        # XOR num with the mask to flip all bits
        # Example: num = 5 (101), mask = 7 (111), result = 2 (010)
        return mask ^ num

# Example usage:
solution = Solution()

# Test case 1
num1 = 5
print(solution.findComplement(num1))  # Output: 2

# Test case 2
num2 = 1
print(solution.findComplement(num2))  # Output: 0
