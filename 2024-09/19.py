# Problem: 241. Different Ways to Add Parentheses
# Link: https://leetcode.com/problems/different-ways-to-add-parentheses/
# Beats: 83.91% (Runtime), 8.08% (Memory)
# Time Complexity: O(n * 2^n), where n is the length of the expression.
# Space Complexity: O(n * 2^n) for storing intermediate results and recursion call stack.

from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        """
        This function computes all possible results from different ways of grouping numbers and operators in the given expression.

        :param expression: A string of numbers and operators ('+', '-', '*').
        :return: A list of all possible results from computing the expression with different groupings.
        """
        # If the expression is purely a number, return it as a list containing the number
        if expression.isdigit():
            return [int(expression)]
        
        # List to store all possible results
        results = []
        
        # Iterate through each character in the expression
        for i, char in enumerate(expression):
            # If the character is an operator
            if char in "+-*":
                # Recursively solve for the left part of the expression (before the operator)
                left_results = self.diffWaysToCompute(expression[:i])
                # Recursively solve for the right part of the expression (after the operator)
                right_results = self.diffWaysToCompute(expression[i+1:])
                
                # Combine results from left and right subexpressions based on the current operator
                for left in left_results:
                    for right in right_results:
                        if char == '+':
                            results.append(left + right)
                        elif char == '-':
                            results.append(left - right)
                        elif char == '*':
                            results.append(left * right)
        
        # Return the list of all possible results
        return results

# Time Complexity:
# O(n * 2^n), where n is the length of the expression. For every operator, we recursively split the expression and compute both parts. The branching factor of 2 at every operator gives the exponential factor.

# Space Complexity:
# O(n * 2^n), since we store intermediate results and the recursion call stack also grows with every division of the expression.

# Example test cases:
print(Solution().diffWaysToCompute("2-1-1"))   # Expected output: [0, 2]
print(Solution().diffWaysToCompute("2*3-4*5")) # Expected output: [-34, -14, -10, -10, 10]
