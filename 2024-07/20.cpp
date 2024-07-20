// Problem: 1605. Find Valid Matrix Given Row and Column Sums
// Link: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
// Beats: Runtime 47 ms (Beats 10.16%), Memory 36.13 MB (Beats 11.51%)

// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns
// Space Complexity: O(m * n), for storing the resultant matrix

#include <iostream>
#include <vector>
#include <algorithm> // For std::min

using namespace std;

class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
    {
        int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> resultMatrix(rows, vector<int>(cols, 0));

        // Fill the matrix with valid values
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                // Determine the value at resultMatrix[i][j] as the minimum of the remaining rowSum and colSum
                resultMatrix[i][j] = min(rowSum[i], colSum[j]);
                // Subtract the placed value from both rowSum and colSum
                rowSum[i] -= resultMatrix[i][j];
                colSum[j] -= resultMatrix[i][j];
            }
        }

        return resultMatrix;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> rowSum1 = {3, 8};
    vector<int> colSum1 = {4, 7};
    vector<vector<int>> result1 = solution.restoreMatrix(rowSum1, colSum1);
    for (const auto &row : result1)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Example 2
    vector<int> rowSum2 = {5, 7, 10};
    vector<int> colSum2 = {8, 6, 8};
    vector<vector<int>> result2 = solution.restoreMatrix(rowSum2, colSum2);
    for (const auto &row : result2)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
