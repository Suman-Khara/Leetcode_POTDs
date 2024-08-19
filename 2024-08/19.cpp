/*
Problem: 650. 2 Keys Keyboard
Link: https://leetcode.com/problems/2-keys-keyboard/

Runtime: 55 ms
Beats: 7.29%
Memory: 157.30 MB
Beats: 8.56%

Time Complexity: O(n^2) - The recursive calls and memoization fill out an n x n DP table.
Space Complexity: O(n^2) - The DP table of size n x n to store intermediate results.

Approach:
- The goal is to achieve exactly `n` 'A's using the minimum number of operations (Copy All and Paste).
- We use dynamic programming (DP) to store and reuse the results of subproblems.
- The DP table `dp[curr][clip]` stores the minimum number of operations needed to reach exactly `curr` 'A's on the screen with `clip` 'A's in the clipboard.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Recursive function with memoization to find the minimum steps
    int findMinSteps(int current, int clipboard, vector<vector<int>> &dp)
    {
        int n = dp.size() - 1;

        // Base cases
        if (current > n || clipboard > n)
            return 1e9; // Return a large number if out of bounds

        if (current == n)
            return 0; // No more steps needed if we have exactly n 'A's

        // Return the previously computed result if available
        if (dp[current][clipboard] != 1e9)
            return dp[current][clipboard];

        int minSteps;

        // Copy All operation
        if (current != clipboard) // Avoid unnecessary copy operations
            minSteps = 1 + findMinSteps(current, current, dp);

        // Paste operation
        if (clipboard != 0) // Can only paste if clipboard is not empty
            minSteps = min(minSteps, 1 + findMinSteps(current + clipboard, clipboard, dp));

        // Store and return the minimum steps needed
        return dp[current][clipboard] = minSteps;
    }

    // Function to calculate the minimum number of steps to get 'n' 'A's
    int minSteps(int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9)); // DP table initialized with large numbers
        return findMinSteps(1, 0, dp);                          // Start with 1 'A' on screen and an empty clipboard
    }
};

int main()
{
    Solution solution;

    // Example 1
    int n1 = 3;
    cout << "Minimum steps to get " << n1 << " 'A's: " << solution.minSteps(n1) << endl; // Expected output: 3

    // Example 2
    int n2 = 1;
    cout << "Minimum steps to get " << n2 << " 'A's: " << solution.minSteps(n2) << endl; // Expected output: 0

    return 0;
}