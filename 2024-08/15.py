# Problem: 860. Lemonade Change
# Link: https://leetcode.com/problems/lemonade-change/
# Beats: 74.66% (Runtime: 613 ms), 15.58% (Memory: 21.26 MB)
# Time Complexity: O(N) - The algorithm processes each bill once.
# Space Complexity: O(1) - The space used for storing change counts is constant.

from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        # Initialize counts for $5 and $10 bills
        count_5 = 0
        count_10 = 0
        
        for bill in bills:
            if bill == 5:
                count_5 += 1
            elif bill == 10:
                if count_5 > 0:
                    count_5 -= 1
                else:
                    return False
                count_10 += 1
            else:  # bill == 20
                if count_10 > 0 and count_5 > 0:
                    count_10 -= 1
                    count_5 -= 1
                elif count_5 >= 3:
                    count_5 -= 3
                else:
                    return False
        
        return True

# Example usage:
solution = Solution()

# Test case 1
bills1 = [5, 5, 5, 10, 20]
print(solution.lemonadeChange(bills1))  # Output: true

# Test case 2
bills2 = [5, 5, 10, 10, 20]
print(solution.lemonadeChange(bills2))  # Output: false
