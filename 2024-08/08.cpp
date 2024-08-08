/*
Problem: Spiral Matrix III
Link: https://leetcode.com/problems/spiral-matrix-iii/

Runtime: 11 ms
Beats: 42.57%
Memory: 13.71 MB
Beats: 36.78%

Time Complexity: O(rows * cols) - Each cell in the grid is visited exactly once.
Space Complexity: O(rows * cols) - Space needed to store the result list.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int startRow, int startCol)
    {
        // Direction vectors for moving in the order: right, down, left, up
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int currentSideLength = 1;       // Initial length of steps in each direction
        int stepsInCurrentSide = 0;      // Steps taken in the current direction
        int currentRow = startRow;       // Current row position
        int currentCol = startCol;       // Current column position
        int directionIndex = 0;          // Current direction index (right -> 0, down -> 1, left -> 2, up -> 3)
        int stepsInCurrentDirection = 0; // Number of steps taken in the current direction
        vector<vector<int>> result;      // Result list to store the coordinates

        // Continue until all cells in the grid are visited
        while (result.size() < rows * cols)
        {
            // Check if the current position is within grid bounds
            if (currentRow >= 0 && currentRow < rows && currentCol >= 0 && currentCol < cols)
            {
                result.push_back({currentRow, currentCol});
            }
            // Move to the next position based on current direction
            currentRow += directions[directionIndex][0];
            currentCol += directions[directionIndex][1];
            stepsInCurrentDirection++;

            // Check if we've completed the steps in the current direction
            if (stepsInCurrentDirection == currentSideLength)
            {
                // Change direction (clockwise)
                directionIndex = (directionIndex + 1) % 4;
                stepsInCurrentDirection = 0;
                stepsInCurrentSide++;
            }

            // Every two directions (right and down or left and up), increase the step length
            if (stepsInCurrentSide == 2)
            {
                stepsInCurrentSide = 0;
                currentSideLength++;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;

    // Example 1
    int rows1 = 1, cols1 = 4, rStart1 = 0, cStart1 = 0;
    vector<vector<int>> result1 = sol.spiralMatrixIII(rows1, cols1, rStart1, cStart1);
    for (const auto &pos : result1)
    {
        cout << "[" << pos[0] << "," << pos[1] << "] ";
    }
    cout << endl;

    // Example 2
    int rows2 = 5, cols2 = 6, rStart2 = 1, cStart2 = 4;
    vector<vector<int>> result2 = sol.spiralMatrixIII(rows2, cols2, rStart2, cStart2);
    for (const auto &pos : result2)
    {
        cout << "[" << pos[0] << "," << pos[1] << "] ";
    }
    cout << endl;

    return 0;
}
