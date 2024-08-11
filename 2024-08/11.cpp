/*
Problem: Minimum Number of Days to Disconnect Island
Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

Runtime: 142 ms
Beats: 19.54%
Memory: 20.28 MB
Beats: 71.55%

Time Complexity: O((m * n) ^ 2) - Counting islands involves scanning the grid, which is O(m * n). For each land cell, it may involve up to O(m * n) operations to check the disconnection status.
Space Complexity: O(m * n) - Space for the visited matrix.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to perform DFS to mark visited cells
    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0 || visited[row][col])
            return;
        visited[row][col] = true;
        // Explore all four directions
        dfs(grid, row - 1, col, visited);
        dfs(grid, row + 1, col, visited);
        dfs(grid, row, col - 1, visited);
        dfs(grid, row, col + 1, visited);
    }

    // Function to count the number of islands in the grid
    int count(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    islandCount++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return islandCount;
    }

    int minDays(vector<vector<int>> &grid)
    {
        // If the grid is already disconnected, return 0
        if (count(grid) != 1)
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        // Try removing each land cell and check if the grid becomes disconnected
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0; // Remove the land cell
                    if (count(grid) != 1)
                    {
                        return 1; // Grid becomes disconnected after removing one cell
                    }
                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }
        return 2; // Grid is still connected even after removing one cell, so we need at least 2 days
    }
};

int main()
{
    Solution sol;

    // Example 1
    vector<vector<int>> grid1 = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << "Minimum number of days: " << sol.minDays(grid1) << endl;

    // Example 2
    vector<vector<int>> grid2 = {{1, 1}};
    cout << "Minimum number of days: " << sol.minDays(grid2) << endl;

    return 0;
}
