/*
Problem: 1905. Count Sub Islands
Link: https://leetcode.com/problems/count-sub-islands/

Time Complexity:
- The algorithm visits each cell in the grid exactly once.
- The depth-first search (DFS) visits all cells of each island, which in the worst case will visit all cells.
- Thus, the time complexity is O(m * n), where m is the number of rows and n is the number of columns.

Space Complexity:
- The space complexity is O(m * n) due to the visited array and the recursion stack in the DFS calls.

Runtime: 450 ms
Beats: 19.94%
Memory: 106.98 MB
Beats: 36.24%
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Helper function to "cancel" an island in grid2 that is not a sub-island
    void cancelIsland(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        grid[i][j] = 0;               // Cancel this cell as visited by setting it to 0
        cancelIsland(grid, i + 1, j); // Check downward
        cancelIsland(grid, i, j + 1); // Check rightward
        cancelIsland(grid, i - 1, j); // Check upward
        cancelIsland(grid, i, j - 1); // Check leftward
    }

    // Depth-first search to determine if the island in grid2 is a sub-island of grid1
    bool isSubIsland(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, vector<vector<bool>> &visited)
    {
        int rows = grid1.size(), cols = grid1[0].size();
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid2[i][j] == 0 || visited[i][j])
            return true;
        if (grid1[i][j] == 0)
        {                              // This part of grid2 is not in grid1
            cancelIsland(grid2, i, j); // Cancel the island in grid2
            return false;
        }
        visited[i][j] = true; // Mark this cell as visited
        bool result = true;
        result &= isSubIsland(grid1, grid2, i + 1, j, visited); // Check downward
        result &= isSubIsland(grid1, grid2, i, j + 1, visited); // Check rightward
        result &= isSubIsland(grid1, grid2, i - 1, j, visited); // Check upward
        result &= isSubIsland(grid1, grid2, i, j - 1, visited); // Check leftward
        return result;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int rows = grid1.size(), cols = grid1[0].size(), count = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Visited array to keep track of visited cells
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Check if the cell is part of an unvisited island in grid2 that is also in grid1
                if (grid1[i][j] == 1 && grid2[i][j] == 1 && !visited[i][j] && isSubIsland(grid1, grid2, i, j, visited))
                {
                    count++; // If it's a valid sub-island, increment the count
                }
            }
        }
        return count; // Return the total number of sub-islands
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<vector<int>> grid1_1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}};
    vector<vector<int>> grid2_1 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0}};
    cout << "Number of sub-islands: " << solution.countSubIslands(grid1_1, grid2_1) << endl; // Expected output: 3

    // Example 2
    vector<vector<int>> grid1_2 = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1}};
    vector<vector<int>> grid2_2 = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}};
    cout << "Number of sub-islands: " << solution.countSubIslands(grid1_2, grid2_2) << endl; // Expected output: 2

    return 0;
}
