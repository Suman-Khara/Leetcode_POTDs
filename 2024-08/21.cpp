/*
Problem: 664. Strange Printer
Link: https://leetcode.com/problems/strange-printer/

Runtime: 11 ms
Beats: 92.47%
Memory: 10.69 MB
Beats: 75.58%

Time Complexity: O(n^3) - Due to the nested loops in the recursive function with memoization.
Space Complexity: O(n^2) - For storing the results of subproblems in the DP table.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Helper function to compute the minimum number of turns needed to print the substring
    int minTurnsToPrint(string &s, int start, int end, vector<vector<int>> &dp)
    {
        if (start > end)
            return 0; // Base case: no characters to print
        if (dp[start][end] != -1)
            return dp[start][end]; // If already computed, return the stored result

        // Initialize with the case of printing s[start] separately and then the rest
        int minTurns = 1 + minTurnsToPrint(s, start + 1, end, dp);

        // Try to merge turns by printing matching characters together
        for (int i = start + 1; i <= end; ++i)
        {
            if (s[i] == s[start])
            {
                minTurns = min(minTurns, minTurnsToPrint(s, start, i - 1, dp) + minTurnsToPrint(s, i + 1, end, dp));
            }
        }

        // Store and return the result
        return dp[start][end] = minTurns;
    }

    // Main function to solve the problem
    int strangePrinter(string s)
    {
        string reducedString;
        reducedString += s[0];

        // Reduce the string to remove consecutive duplicate characters
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                reducedString += s[i];
            }
        }

        int n = reducedString.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // DP table

        // Solve the problem using the helper function
        return minTurnsToPrint(reducedString, 0, n - 1, dp);
    }
};

int main()
{
    Solution solution;

    // Example 1
    string s1 = "aaabbb";
    cout << "Minimum turns for 'aaabbb': " << solution.strangePrinter(s1) << endl; // Expected output: 2

    // Example 2
    string s2 = "aba";
    cout << "Minimum turns for 'aba': " << solution.strangePrinter(s2) << endl; // Expected output: 2

    return 0;
}
