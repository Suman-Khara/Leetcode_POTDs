// Problem: 1380. Lucky Numbers in a Matrix
// Link: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
// Beats: Runtime 16 ms (Beats 56.65%), Memory 14.44 MB (Beats 16.09%)

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix
// Space Complexity: O(m + n), for storing the minimum of each row and maximum of each column

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<int> findLuckyNumbers(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> minRow(rows, INT_MAX), maxCol(cols, INT_MIN), luckyNumbers;

        // Find the minimum element in each row and the maximum element in each column
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                minRow[i] = min(minRow[i], matrix[i][j]);
                maxCol[j] = max(maxCol[j], matrix[i][j]);
            }
        }

        // Check for elements that are both the minimum in their row and the maximum in their column
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j])
                {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<vector<int>> matrix1 = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    vector<int> result1 = solution.findLuckyNumbers(matrix1);
    for (int num : result1)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 15

    // Example 2
    vector<vector<int>> matrix2 = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<int> result2 = solution.findLuckyNumbers(matrix2);
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 12

    // Example 3
    vector<vector<int>> matrix3 = {{7, 8}, {1, 2}};
    vector<int> result3 = solution.findLuckyNumbers(matrix3);
    for (int num : result3)
    {
        cout << num << " ";
    }
    cout << endl; // Output: 7

    return 0;
}
