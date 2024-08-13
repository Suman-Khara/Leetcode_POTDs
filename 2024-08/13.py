# Problem: 40. Combination Sum II
# Link: https://leetcode.com/problems/combination-sum-ii/
# Beats: 98.46% (Runtime: 36 ms), 30.23% (Memory: 16.68 MB)
# Time Complexity: O(2^N) - The backtracking algorithm explores all possible subsets, which can lead to exponential time complexity in the worst case.
# Space Complexity: O(N) - The space complexity is mainly due to the depth of the recursion stack and storing the result.

from typing import List

class Solution:
    def combinationSum2(self, nums: List[int], target: int) -> List[List[int]]:
        def backtrack(current_combination, current_sum, start_index):
            if current_sum == target:
                result.append(current_combination[:])
                return
            elif current_sum > target:
                return
            
            for i in range(start_index, len(nums)):
                # Skip duplicate elements
                if i > start_index and nums[i] == nums[i - 1]:
                    continue
                if current_sum + nums[i] > target:
                    break
                # Include nums[i] in the current combination
                current_combination.append(nums[i])
                backtrack(current_combination, current_sum + nums[i], i + 1)
                # Backtrack: remove nums[i] from the current combination
                current_combination.pop()
        
        # Sort the numbers to handle duplicates and enable efficient pruning
        nums.sort()
        result = []
        backtrack([], 0, 0)
        return result

# Example usage:
solution = Solution()

# Test case 1
nums1 = [10, 1, 2, 7, 6, 1, 5]
target1 = 8
print(solution.combinationSum2(nums1, target1))  # Output: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]

# Test case 2
nums2 = [2, 5, 2, 1, 2]
target2 = 5
print(solution.combinationSum2(nums2, target2))  # Output: [[1, 2, 2], [5]]
