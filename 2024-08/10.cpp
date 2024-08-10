/*
Problem: Regions Cut By Slashes
Link: https://leetcode.com/problems/regions-cut-by-slashes/

Runtime: 27 ms
Beats: 12.20%
Memory: 13.62 MB
Beats: 28.73%

Time Complexity: O(n^2) - Each cell is processed a constant number of times.
Space Complexity: O(n^2) - Space for the 3*n x 3*n matrix and the recursion stack.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Depth-first search to mark all connected cells
    void dfs(vector<vector<bool>> &grid, int i, int j)
    {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || !grid[i][j])
            return;
        grid[i][j] = false; // Mark this cell as visited
        // Explore all four directions
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        // Initialize a 3n x 3n matrix to represent each 1x1 square divided into 9 cells
        vector<vector<bool>> matrix(n * 3, vector<bool>(n * 3, true));

        // Populate the matrix based on the slashes in the input grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ni = 3 * i, nj = 3 * j;
                if (grid[i][j] == '\\')
                {
                    // Backslash '/' divides the cell into two regions
                    matrix[ni][nj] = false;         // Top-left
                    matrix[ni + 1][nj + 1] = false; // Center
                    matrix[ni + 2][nj + 2] = false; // Bottom-right
                }
                else if (grid[i][j] == '/')
                {
                    // Slash '/' divides the cell into two regions
                    matrix[ni + 2][nj] = false;     // Bottom-left
                    matrix[ni + 1][nj + 1] = false; // Center
                    matrix[ni][nj + 2] = false;     // Top-right
                }
            }
        }

        int regionsCount = 0;
        // Perform DFS to count the number of regions
        for (int i = 0; i < 3 * n; i++)
        {
            for (int j = 0; j < 3 * n; j++)
            {
                if (matrix[i][j])
                { // If the cell is part of a new region
                    regionsCount++;
                    dfs(matrix, i, j); // Mark all cells in this region
                }
            }
        }
        return regionsCount;
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<string> grid1 = {" /", "/ "};
    cout << "Number of regions: " << sol.regionsBySlashes(grid1) << endl;

    // Example 2
    vector<string> grid2 = {" /", "  "};
    cout << "Number of regions: " << sol.regionsBySlashes(grid2) << endl;

    // Example 3
    vector<string> grid3 = {"/\\", "\\/"};
    cout << "Number of regions: " << sol.regionsBySlashes(grid3) << endl;

    return 0;
}
