// Problem: 874. Walking Robot Simulation
// Link: https://leetcode.com/problems/walking-robot-simulation/
// Beats 27.90% with 119 ms runtime, 65.75% with 39.50 MB memory usage

/*
Time Complexity:
1. The main loop over commands: O(c), where c is the number of commands.
2. Each movement within a command: O(k), where k is the movement distance.
3. Checking obstacles for each step: O(1) since we use an unordered set for fast lookup.
   - This gives us O(k) per command.
4. Overall time complexity: O(c * k), which simplifies to O(c), as k is bounded by the command's maximum value (9).

Space Complexity:
1. Storing obstacles in an unordered set: O(o), where o is the number of obstacles.
2. The space required for direction vectors and variables is constant.
   - Overall space complexity: O(o).
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    // Define direction vectors for North, East, South, and West.
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        // Create a set to store obstacle positions for fast lookup.
        unordered_set<string> obstacleSet;
        for (vector<int> &obstacle : obstacles)
        {
            obstacleSet.insert(to_string(obstacle[0]) + "|" + to_string(obstacle[1]));
        }

        int maxDistance = 0;
        int x = 0, y = 0;       // Robot's starting position
        int directionIndex = 0; // Start facing North (0th direction)

        for (int command : commands)
        {
            if (command == -1)
            {
                // Turn right 90 degrees
                directionIndex = (directionIndex + 1) % 4;
            }
            else if (command == -2)
            {
                // Turn left 90 degrees
                directionIndex = (directionIndex + 3) % 4;
            }
            else
            {
                // Move forward command units
                for (int step = 0; step < command; step++)
                {
                    int nextX = x + directions[directionIndex][0];
                    int nextY = y + directions[directionIndex][1];

                    // Check if the next position is an obstacle
                    if (obstacleSet.count(to_string(nextX) + "|" + to_string(nextY)))
                    {
                        break; // Stop moving if there's an obstacle
                    }
                    else
                    {
                        x = nextX;
                        y = nextY;
                        // Update the maximum distance squared
                        maxDistance = max(maxDistance, x * x + y * y);
                    }
                }
            }
        }
        return maxDistance;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<int> commands1 = {4, -1, 3};
    vector<vector<int>> obstacles1 = {};
    cout << solution.robotSim(commands1, obstacles1) << endl; // Expected output: 25

    // Test case 2
    vector<int> commands2 = {4, -1, 4, -2, 4};
    vector<vector<int>> obstacles2 = {{2, 4}};
    cout << solution.robotSim(commands2, obstacles2) << endl; // Expected output: 65

    // Test case 3
    vector<int> commands3 = {6, -1, -1, 6};
    vector<vector<int>> obstacles3 = {};
    cout << solution.robotSim(commands3, obstacles3) << endl; // Expected output: 36

    return 0;
}
