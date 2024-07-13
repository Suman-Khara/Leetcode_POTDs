// Problem: 2751. Robot Collisions
// Link: https://leetcode.com/problems/robot-collisions/description/
// Beats: Runtime 526 ms (Beats 11.45%), Memory 232.64 MB (Beats 32.06%)

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        map<int, pair<int, char>> robots;
        int n = positions.size();

        // Storing robots in a map by their positions
        for (int i = 0; i < n; i++)
        {
            robots[positions[i]] = {healths[i], directions[i]};
        }

        stack<pair<int, int>> st;

        // Simulating the movement and collisions of robots
        for (const auto &robot : robots)
        {
            int pos = robot.first, health = robot.second.first;
            char dir = robot.second.second;

            if (st.empty() || dir == 'R')
            {
                st.push({pos, health}); // Pushing right-moving robots onto stack
            }
            else if (dir == 'L')
            {
                bool survived = true;
                while (!st.empty() && robots[st.top().first].second == 'R')
                {
                    int prev_pos = st.top().first, prev_health = st.top().second;
                    if (prev_health > health)
                    {
                        robots[pos].first = 0;
                        robots[prev_pos].first--;
                        st.top().second--;
                        survived = false;
                        break;
                    }
                    else if (prev_health == health)
                    {
                        robots[pos].first = 0;
                        robots[prev_pos].first = 0;
                        st.pop();
                        survived = false;
                        break;
                    }
                    else
                    {
                        robots[prev_pos].first = 0;
                        robots[pos].first--;
                        health--;
                        st.pop();
                    }
                }
                if (survived)
                {
                    st.push({pos, health});
                }
            }
        }

        vector<int> result;
        for (int pos : positions)
        {
            if (robots[pos].first > 0)
            {
                result.push_back(robots[pos].first); // Collecting healths of surviving robots
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> positions1 = {5, 4, 3, 2, 1};
    vector<int> healths1 = {2, 17, 9, 15, 10};
    string directions1 = "RRRRR";
    vector<int> result1 = solution.survivedRobotsHealths(positions1, healths1, directions1);
    for (int health : result1)
    {
        cout << health << " ";
    }
    cout << endl; // Expected: 2 17 9 15 10

    vector<int> positions2 = {3, 5, 2, 6};
    vector<int> healths2 = {10, 10, 15, 12};
    string directions2 = "RLRL";
    vector<int> result2 = solution.survivedRobotsHealths(positions2, healths2, directions2);
    for (int health : result2)
    {
        cout << health << " ";
    }
    cout << endl; // Expected: 14

    vector<int> positions3 = {1, 2, 5, 6};
    vector<int> healths3 = {10, 10, 11, 11};
    string directions3 = "RLRL";
    vector<int> result3 = solution.survivedRobotsHealths(positions3, healths3, directions3);
    for (int health : result3)
    {
        cout << health << " ";
    }
    cout << endl; // Expected: []

    return 0;
}
