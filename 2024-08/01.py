# Problem: 2678. Number of Senior Citizens
# Link: https://leetcode.com/problems/number-of-senior-citizens/
# Beats: Runtime 45 ms (Beats 66.83%), Memory 16.46 MB (Beats 75.00%)

# Time Complexity: O(n), where n is the number of elements in the details list
# Space Complexity: O(1), constant space usage

from typing import List

class Solution:
    # Function to count the number of senior citizens
    def countSeniors(self, details: List[str]) -> int:
        # Initialize the count of senior citizens
        count_seniors = 0
        
        # Iterate through each passenger detail string
        for detail in details:
            # Extract the age of the passenger from the detail string and check if it's greater than 60
            if int(detail[11:13]) > 60:
                count_seniors += 1
        
        return count_seniors


# Example Usage
solution = Solution()

# Example 1
details1 = ["7868190130M7522", "5303914400F9211", "9273338290F4010"]
print(solution.countSeniors(details1))  # Output: 2

# Example 2
details2 = ["1313579440F2036", "2921522980M5644"]
print(solution.countSeniors(details2))  # Output: 0