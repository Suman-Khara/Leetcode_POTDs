# Problem: 840. Magic Squares In Grid
# Link: https://leetcode.com/problems/magic-squares-in-grid/
# Beats: 31.28% (Runtime: 44 ms), 53.33% (Memory: 16.58 MB)
# Time Complexity: O(R * C) - We iterate over (R-2)*(C-2) possible 3x3 subgrids and check each of the 9 elements.
# Space Complexity: O(1) - The space used for checking the magic square is constant.

from typing import List

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def isMagicSquare(square: List[List[int]]) -> bool:
            # Check if all numbers are distinct and in the range 1 to 9
            nums = set()
            for row in square:
                for num in row:
                    if num < 1 or num > 9:
                        return False
                    nums.add(num)
            if len(nums) != 9:
                return False
            
            # Check if the sum of rows is 15
            for row in square:
                if sum(row) != 15:
                    return False
            
            # Check if the sum of columns is 15
            for col in range(3):
                if sum(square[row][col] for row in range(3)) != 15:
                    return False
            
            # Check if the sum of the diagonals is 15
            if (square[0][0] + square[1][1] + square[2][2] != 15 or
                square[2][0] + square[1][1] + square[0][2] != 15):
                return False
            
            return True
        
        rows, cols = len(grid), len(grid[0])
        count = 0
        
        # Iterate over all possible 3x3 subgrids
        for r in range(2, rows):
            for c in range(2, cols):
                # Extract the 3x3 subgrid
                subgrid = [grid[r-i][c-2:c+1] for i in range(3)]
                if isMagicSquare(subgrid):
                    count += 1
        
        return count

# Example test cases
solution = Solution()

# Test case 1
grid1 = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
print(solution.numMagicSquaresInside(grid1))  # Output: 1

# Test case 2
grid2 = [[8]]
print(solution.numMagicSquaresInside(grid2))  # Output: 0