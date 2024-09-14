// Problem: 2419. Longest Subarray With Maximum Bitwise AND
// Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
// Beats: Runtime 110 ms (Beats 36.84%), Memory 84.98 MB (Beats 34.21%)

// Time Complexity: O(n), where n is the length of the array `nums`.
// Space Complexity: O(1), only constant extra space is used.

#include <iostream>
#include <vector>
#include <algorithm> // For max_element

using namespace std;

class Solution
{
public:
    // Function to find the longest subarray with maximum bitwise AND
    int longestSubarray(vector<int> &nums)
    {
        int maxElement = *max_element(nums.begin(), nums.end()); // Find the maximum element in the array
        int maxLength = 0, currentLength = 0;

        // Traverse the array to find the longest subarray with elements equal to maxElement
        for (int num : nums)
        {
            if (num == maxElement)
            {
                currentLength++; // Increment length if the current element is equal to maxElement
            }
            else
            {
                currentLength = 0; // Reset the length if the current element is not equal to maxElement
            }
            maxLength = max(maxLength, currentLength); // Update the maximum length
        }

        return maxLength;
    }
};

// Main function to test the solution
int main()
{
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 3, 2, 2};
    int result1 = solution.longestSubarray(nums1);
    cout << "Result for Example 1: " << result1 << endl; // Output: 2

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    int result2 = solution.longestSubarray(nums2);
    cout << "Result for Example 2: " << result2 << endl; // Output: 1

    return 0;
}
