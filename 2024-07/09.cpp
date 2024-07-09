// Problem: 1701. Average Waiting Time
// Link: https://leetcode.com/problems/average-waiting-time/
// Beats: Runtime 188 ms (Beats 16.47%), Memory 86.78 MB (Beats 6.47%)

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double sum = 0, time = 0;
        for (vector<int> &v : customers)
        {
            time = max(time, (double)v[0]) + v[1]; // Calculate the end time of the current order
            sum += time - v[0];                    // Add the waiting time for the current customer
        }
        return sum / customers.size(); // Calculate the average waiting time
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> customers1 = {{1, 2}, {2, 5}, {4, 3}};
    cout << "Average waiting time: " << solution.averageWaitingTime(customers1) << endl;

    vector<vector<int>> customers2 = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};
    cout << "Average waiting time: " << solution.averageWaitingTime(customers2) << endl;

    return 0;
}
