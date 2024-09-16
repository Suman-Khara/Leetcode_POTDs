// Problem: 539. Minimum Time Difference
// Link: https://leetcode.com/problems/minimum-time-difference/
// Beats: 53.24% with 13 ms runtime, 30.60% with 17.92 MB memory usage

/*
Time Complexity: O(n log n)
- The time complexity is dominated by the sorting of the `timePoints` array, which takes O(n log n). After sorting, calculating the differences between adjacent times takes O(n), making the overall complexity O(n log n).

Space Complexity: O(1)
- The space complexity is O(1), ignoring the space required to store the input, as we perform operations in-place on the sorted list and use only a few variables for calculations.
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm> // for sort

using namespace std;

class Solution
{
public:
    // Function to calculate the time difference between two time points
    int timeDifference(string t1, string t2)
    {
        int minutes1 = stoi(t1.substr(0, 2)) * 60 + stoi(t1.substr(3, 2)); // Convert t1 to minutes
        int minutes2 = stoi(t2.substr(0, 2)) * 60 + stoi(t2.substr(3, 2)); // Convert t2 to minutes

        // Return the minimum of the direct difference and the wrap-around difference (24*60 = 1440 minutes in a day)
        return min(abs(minutes2 - minutes1), 1440 - abs(minutes2 - minutes1));
    }

    int findMinDifference(vector<string> &timePoints)
    {
        sort(timePoints.begin(), timePoints.end()); // Sort the time points
        int minDifference = INT_MAX;                // Initialize the minimum difference with a large value
        int n = timePoints.size();

        // Calculate the minimum time difference between adjacent time points
        for (int i = 0; i < n; i++)
        {
            minDifference = min(minDifference, timeDifference(timePoints[i], timePoints[(i + 1) % n]));
            if (minDifference == 0) // If minimum difference is 0, return immediately as we cannot get a smaller value
                return minDifference;
        }

        return minDifference;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<string> timePoints1 = {"23:59", "00:00"};
    cout << "Example 1 Output: " << solution.findMinDifference(timePoints1) << endl; // Expected output: 1

    // Example 2
    vector<string> timePoints2 = {"00:00", "23:59", "00:00"};
    cout << "Example 2 Output: " << solution.findMinDifference(timePoints2) << endl; // Expected output: 0

    return 0;
}
