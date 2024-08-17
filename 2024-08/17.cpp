/*
Problem: Maximum Number of Points with Cost
Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/

Runtime: 184 ms
Beats: 68.12%
Memory: 104.90 MB
Beats: 60.49%

Time Complexity: O(m * n) - We process each cell of the matrix a constant number of times.
Space Complexity: O(m * n) - Space for the dp matrix.
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the maximum of two numbers
    long long max(long long a, long long b)
    {
        return a < b ? b : a;
    }

    long long maxPoints(vector<vector<int>> &points)
    {
        int rows = points.size();
        int cols = points[0].size();
        vector<vector<long long>> dp(rows, vector<long long>(cols, 0));

        // Initialize the dp array for the first row
        for (int j = 0; j < cols; j++)
        {
            dp[0][j] = points[0][j];
        }

        // Iterate through each row starting from the second one
        for (int i = 1; i < rows; i++)
        {
            long long prev_left = dp[i - 1][0];                      // Maximum value from the left side of the previous row
            long long prev_right = dp[i - 1][cols - 1] - (cols - 1); // Maximum value from the right side of the previous row

            // Calculate maximum points for each cell considering the left to right traversal
            for (int j = 0; j < cols; j++)
            {
                prev_left = max(prev_left, dp[i - 1][j] + j);
                dp[i][j] = max(dp[i][j], prev_left + points[i][j] - j);
            }

            // Calculate maximum points for each cell considering the right to left traversal
            for (int j = cols - 1; j >= 0; j--)
            {
                prev_right = max(prev_right, dp[i - 1][j] - j);
                dp[i][j] = max(dp[i][j], points[i][j] + j + prev_right);
            }
        }

        // Return the maximum value from the last row
        return *max_element(dp.back().begin(), dp.back().end());
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<vector<int>> points1 = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    cout << "Maximum number of points: " << sol.maxPoints(points1) << endl;

    // Example 2
    vector<vector<int>> points2 = {{1, 5}, {2, 3}, {4, 2}};
    cout << "Maximum number of points: " << sol.maxPoints(points2) << endl;

    return 0;
}
